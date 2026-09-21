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
    wire [9:0] sram_wr_addr;   // from AIPU (memory_ctrl)
    wire       sram_wr_en;     // from AIPU
    wire [7:0] sram_wr_data;   // from AIPU

    // UART write port — written by 0xBB command parser when !busy
    reg       uart_wr_en   = 0;
    reg [9:0] uart_wr_addr = 0;
    reg [7:0] uart_wr_data = 0;

    // Mux: UART write takes priority when active (AIPU is never writing at the same time)
    wire       final_wr_en   = sram_wr_en | uart_wr_en;
    wire [9:0] final_wr_addr = uart_wr_en ? uart_wr_addr : sram_wr_addr;
    wire [7:0] final_wr_data = uart_wr_en ? uart_wr_data : sram_wr_data;

    wire [7:0] sram_rd_data;

    reg [10:0] k;
    initial begin
        for (k = 0; k < 1024; k = k + 1)
            sram[k[9:0]] = k[7:0];   // sram[i] = i[7:0]
    end

    assign sram_rd_data = sram[sram_rd_addr];
    always @(posedge clk)
        if (final_wr_en) sram[final_wr_addr] <= final_wr_data;

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
    reg [1:0]  precision     = 2'b00;  // 00=INT8 01=FP8 10=BF16(stub)
    reg        task_valid    = 0;
    reg [7:0]  task_id       = 8'd1;
    reg [31:0] task_cycles   = 32'd300;
    reg        mem_start     = 0;
    reg [0:0]  mem_chain_row = 0;  // 1-bit: 0 or 1 (for G=2)
    reg [0:0]  mem_chain_col = 0;  // 1-bit: 0 or 1 (for G=2)
    reg [9:0]  mem_src_addr  = 10'd0;
    reg [9:0]  mem_dst_addr  = 10'd512;
    reg [31:0] mem_num_rows  = 32'd4;

    // ----------------------------------------------------------------
    // Command protocol
    //
    // COMPUTE packet (8 bytes):
    //   0xAA [SRC_HI] [SRC_LO] [DST_HI] [DST_LO] [0x02] [0x00] [0x55]
    //   Triggers computation using given SRAM src/dst addresses.
    //
    // WRITE packet (4 + len bytes):
    //   0xBB [ADDR_HI] [ADDR_LO] [LEN] [byte_0] ... [byte_LEN-1]
    //   Writes LEN bytes to SRAM starting at ADDR. Only valid when !busy.
    //
    // Legacy single byte (any byte not 0xAA or 0xBB):
    //   Re-triggers computation with current src/dst addresses.
    // ----------------------------------------------------------------
    localparam PKT_LEN = 8;
    reg [7:0] pkt_buf [0:PKT_LEN-1];
    reg [2:0] pkt_idx = 0;

    // Command parser states
    localparam CMD_IDLE      = 3'd0;
    localparam CMD_COMPUTE   = 3'd1;  // accumulating 0xAA packet bytes
    localparam CMD_WR_ADDRHI = 3'd2;  // waiting for addr_hi of 0xBB packet
    localparam CMD_WR_ADDRLO = 3'd3;  // waiting for addr_lo
    localparam CMD_WR_LEN    = 3'd4;  // waiting for length byte
    localparam CMD_WR_DATA   = 3'd5;  // receiving data bytes

    reg [2:0]  cmd_state    = CMD_IDLE;
    reg [9:0]  wr_cur_addr  = 0;
    reg [7:0]  wr_remaining = 0;

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
            cmd_state    <= CMD_IDLE;
            wr_cur_addr  <= 0;
            wr_remaining <= 0;
            uart_wr_en   <= 0;
            mem_src_addr <= 10'd0;
            mem_dst_addr <= 10'd512;
        end else begin
            task_valid <= 0;
            mem_start  <= 0;
            uart_wr_en <= 0;   // default: no UART write this cycle

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

            // --- UART RX command parser ---
            if (rx_valid && fired) begin
                case (cmd_state)

                    CMD_IDLE: begin
                        if (rx_data == 8'hAA) begin
                            // Start of compute packet
                            pkt_buf[0] <= rx_data;
                            pkt_idx    <= 0;
                            cmd_state  <= CMD_COMPUTE;
                        end else if (rx_data == 8'hBB && !busy) begin
                            // Start of write packet
                            cmd_state <= CMD_WR_ADDRHI;
                        end else if (!busy) begin
                            // Legacy single-byte trigger
                            task_valid <= 1;
                            trig       <= 3'd4;
                            busy       <= 1;
                        end
                    end

                    CMD_COMPUTE: begin
                        pkt_idx <= pkt_idx + 1;
                        pkt_buf[pkt_idx + 1] <= rx_data;
                        if (pkt_idx == PKT_LEN - 2) begin
                            // All 8 bytes received — validate end marker
                            cmd_state <= CMD_IDLE;
                            if (rx_data == 8'h55 && !busy) begin
                                mem_src_addr <= {pkt_buf[1][1:0], pkt_buf[2]};
                                mem_dst_addr <= {pkt_buf[3][1:0], pkt_buf[4]};
                                precision    <= pkt_buf[5][1:0];  // byte5: precision
                                task_valid   <= 1;
                                trig         <= 3'd4;
                                busy         <= 1;
                            end
                        end
                    end

                    CMD_WR_ADDRHI: begin
                        wr_cur_addr[9:8] <= rx_data[1:0];
                        cmd_state        <= CMD_WR_ADDRLO;
                    end

                    CMD_WR_ADDRLO: begin
                        wr_cur_addr[7:0] <= rx_data;
                        cmd_state        <= CMD_WR_LEN;
                    end

                    CMD_WR_LEN: begin
                        wr_remaining <= rx_data;
                        if (rx_data == 8'd0)
                            cmd_state <= CMD_IDLE;  // zero-length write = no-op
                        else
                            cmd_state <= CMD_WR_DATA;
                    end

                    CMD_WR_DATA: begin
                        // Write one byte to SRAM this cycle
                        uart_wr_en   <= 1;
                        uart_wr_addr <= wr_cur_addr;
                        uart_wr_data <= rx_data;
                        wr_cur_addr  <= wr_cur_addr + 1;
                        wr_remaining <= wr_remaining - 1;
                        if (wr_remaining == 8'd1)
                            cmd_state <= CMD_IDLE;
                    end

                    default: cmd_state <= CMD_IDLE;
                endcase
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
        .G(2), .C(1), .N(4),
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
        .precision    (precision),
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
