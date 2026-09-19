/* verilator lint_off UNUSEDSIGNAL */
module top_fpga(
    input  clk,           // H11 — 27 MHz oscillator
    output uart_tx_pin,   // M11 — UART TX to ESP32 (SH1.0 Pin 2)
    input  uart_rx_pin    // T13 — UART RX from ESP32 (SH1.0 Pin 3)
);
    // ----------------------------------------------------------------
    // Power-on reset: hold HIGH for 8 cycles
    // ----------------------------------------------------------------
    reg [2:0] rst_cnt = 0;
    reg       reset   = 1;
    always @(posedge clk) begin
        if (rst_cnt < 7) begin rst_cnt <= rst_cnt + 1; reset <= 1; end
        else reset <= 0;
    end

    // ----------------------------------------------------------------
    // 1 KB SRAM
    // ----------------------------------------------------------------
    reg [7:0] sram [0:1023];
    reg [9:0] sram_rd_addr;
    wire [9:0] sram_wr_addr;
    wire       sram_wr_en;
    wire [7:0] sram_wr_data;
    wire [7:0] sram_rd_data;

    reg [10:0] k;
    initial begin
        for (k = 0; k < 1024; k = k + 1)
            sram[k[9:0]] = k[7:0];   // sram[i] = i[7:0]
    end

    assign sram_rd_data = sram[sram_rd_addr];
    always @(posedge clk)
        if (sram_wr_en) sram[sram_wr_addr] <= sram_wr_data;

    // ----------------------------------------------------------------
    // UART RX — receives bytes from ESP32 (PC → FPGA)
    // ----------------------------------------------------------------
    wire [7:0] rx_data;
    wire       rx_valid;
    uart_rx #(
        .CLK_FREQ (27_000_000),
        .BAUD_RATE(115_200)
    ) urx (
        .clk       (clk),
        .reset     (reset),
        .rx        (uart_rx_pin),
        .data_out  (rx_data),
        .data_ready(rx_valid)
    );

    // ----------------------------------------------------------------
    // Task descriptor registers
    // ----------------------------------------------------------------
    reg        task_valid    = 0;
    reg [7:0]  task_id       = 8'd1;
    reg [31:0] task_cycles   = 32'd100;
    reg        mem_start     = 0;
    reg [0:0]  mem_chain_row = 0;
    reg [0:0]  mem_chain_col = 0;
    reg [9:0]  mem_src_addr  = 10'd0;
    reg [9:0]  mem_dst_addr  = 10'd512;
    reg [31:0] mem_num_rows  = 32'd4;

    // ----------------------------------------------------------------
    // Task protocol parser
    // Packet: 0xAA  SRC_HI SRC_LO  DST_HI DST_LO  OUT_HI OUT_LO  0x55
    //         [0]   [1]    [2]     [3]    [4]     [5]    [6]     [7]
    // 8 bytes total. On valid packet: trigger computation with given addrs.
    // Any single byte (not 0xAA) also works as a simple re-trigger (legacy).
    // ----------------------------------------------------------------
    localparam PKT_LEN = 8;
    reg [7:0] pkt_buf [0:PKT_LEN-1];
    reg [2:0] pkt_idx = 0;   // 0..7
    reg       pkt_armed = 0; // seen 0xAA start marker

    // ----------------------------------------------------------------
    // Boot sequencer + re-trigger
    // ----------------------------------------------------------------
    reg [25:0] startup_cnt = 0;
    localparam BOOT_DELAY  = 26'd54_000_000; // 2s at 27 MHz

    reg fired = 0;
    reg busy  = 0;
    reg [2:0] trig = 0; // countdown: assert mem_start 4 cycles after task_valid

    wire mem_done;

    always @(posedge clk) begin
        if (reset) begin
            startup_cnt  <= 0;
            task_valid   <= 0;
            mem_start    <= 0;
            fired        <= 0;
            busy         <= 0;
            trig         <= 0;
            pkt_idx      <= 0;
            pkt_armed    <= 0;
            mem_src_addr <= 10'd0;
            mem_dst_addr <= 10'd512;
        end else begin
            task_valid <= 0;
            mem_start  <= 0;

            // --- Boot-time one-shot ---
            if (!fired) begin
                if (startup_cnt < BOOT_DELAY + 12)
                    startup_cnt <= startup_cnt + 1;
                if (startup_cnt == BOOT_DELAY)      begin task_valid <= 1; end
                if (startup_cnt == BOOT_DELAY + 10) begin mem_start  <= 1; busy <= 1; end
                if (startup_cnt == BOOT_DELAY + 11) begin fired <= 1; end
            end

            // --- Completion ---
            if (mem_done) busy <= 0;

            // --- UART RX packet parser ---
            if (rx_valid && fired) begin
                if (rx_data == 8'hAA) begin
                    // Start of structured packet
                    pkt_armed <= 1;
                    pkt_idx   <= 0;
                    pkt_buf[0] <= rx_data;
                end else if (pkt_armed) begin
                    pkt_idx <= pkt_idx + 1;
                    pkt_buf[pkt_idx + 1] <= rx_data;

                    if (pkt_idx == PKT_LEN - 2) begin
                        // Received all 8 bytes — check end marker
                        pkt_armed <= 0;
                        if (rx_data == 8'h55 && !busy) begin
                            // Valid structured packet — extract addresses
                            mem_src_addr <= {pkt_buf[1][1:0], pkt_buf[2]};
                            mem_dst_addr <= {pkt_buf[3][1:0], pkt_buf[4]};
                            // pkt_buf[5..6] = output addr (alias of dst for now)
                            task_valid   <= 1;
                            trig         <= 3'd4;
                            busy         <= 1;
                        end
                    end
                end else if (!busy) begin
                    // Single byte (not 0xAA) = legacy trigger, keep current addrs
                    task_valid <= 1;
                    trig       <= 3'd4;
                    busy       <= 1;
                end
            end

            // --- Countdown to mem_start ---
            if (trig > 3'd1)
                trig <= trig - 1;
            else if (trig == 3'd1) begin
                mem_start <= 1;
                trig      <= 0;
            end
        end
    end

    // ----------------------------------------------------------------
    // AIPU top-level
    // ----------------------------------------------------------------
    wire task_accepted;
    wire queue_full;
    wire [3:0] queue_count;

    top #(
        .G(1), .C(1), .N(4),
        .QDEPTH(8),
        .SRAM_DEPTH(1024),
        .CLK_FREQ(27_000_000),
        .BAUD_RATE(115_200)
    ) aipu (
        .clk          (clk),
        .reset        (reset),
        .task_valid   (task_valid),
        .task_id      (task_id),
        .task_cycles  (task_cycles),
        .task_accepted(task_accepted),
        .queue_full   (queue_full),
        .queue_count  (queue_count),
        .mem_start    (mem_start),
        .mem_chain_row(mem_chain_row),
        .mem_chain_col(mem_chain_col),
        .mem_src_addr (mem_src_addr),
        .mem_dst_addr (mem_dst_addr),
        .mem_num_rows (mem_num_rows),
        .mem_done     (mem_done),
        .sram_rd_addr (sram_rd_addr),
        .sram_wr_addr (sram_wr_addr),
        .sram_wr_en   (sram_wr_en),
        .sram_wr_data (sram_wr_data),
        .sram_rd_data (sram_rd_data),
        .uart_tx_pin  (uart_tx_pin)
    );
endmodule
