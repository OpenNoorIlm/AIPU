/* verilator lint_off UNUSEDSIGNAL */
module dispatcher #(
    parameter G      = 2,
    parameter QDEPTH = 8
)(
    input clk,
    input reset,
    input             task_valid,
    input  [7:0]      task_id,
    input  [31:0]     task_cycles,
    output reg        task_accepted,
    output            queue_full,
    output [$clog2(QDEPTH):0] queue_count,
    output reg enable[0:G-1][0:G-1],
    output reg [7:0] active_task[0:G-1][0:G-1],
    input      done[0:G-1][0:G-1]
);

    reg [7:0]  q_id    [0:QDEPTH-1];
    reg [31:0] q_cycles[0:QDEPTH-1];
    reg        q_valid [0:QDEPTH-1];
    reg [$clog2(QDEPTH)-1:0] wr_ptr, rd_ptr;
    reg [$clog2(QDEPTH):0]   count;
    reg        chain_busy [0:G-1][0:G-1];
    reg [31:0] chain_timer[0:G-1][0:G-1];

    assign queue_full  = (count == QDEPTH);
    assign queue_count = count;

    integer r, c;
    reg found; // flag     only assign one task per cycle

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            wr_ptr        <= 0;
            rd_ptr        <= 0;
            count         <= 0;
            task_accepted <= 0;
            for (r = 0; r < G; r = r + 1) begin
                for (c = 0; c < G; c++) begin
                    enable[r][c]      <= 0;
                    chain_busy[r][c]  <= 0;
                    chain_timer[r][c] <= 0;
                    active_task[r][c] <= 0;
                end
            end
            for (r = 0; r < QDEPTH; r++)
                q_valid[r] <= 0;
        end else begin
            task_accepted <= 0;

            // 1. push new task into queue
            if (task_valid && !queue_full) begin
                q_id    [wr_ptr] <= task_id;
                q_cycles[wr_ptr] <= task_cycles;
                q_valid [wr_ptr] <= 1;
                wr_ptr           <= wr_ptr + 1;
                count            <= count + 1;
                task_accepted    <= 1;
            end

            // 2. assign ONE task to first free chain
            found <= 0;
            if (count > 0) begin
                for (r = 0; r < G; r = r + 1) begin
                    for (c = 0; c < G; c++) begin
                        if (!found && !chain_busy[r][c] && q_valid[rd_ptr]) begin
                            enable[r][c]      <= 1;
                            chain_busy[r][c]  <= 1;
                            chain_timer[r][c] <= q_cycles[rd_ptr];
                            active_task[r][c] <= q_id[rd_ptr];
                            q_valid[rd_ptr]   <= 0;
                            rd_ptr            <= rd_ptr + 1;
                            count             <= count - 1;
                            found             <= 1; // stop after first
                        end
                    end
                end
            end

            // 3. tick timers
            for (r = 0; r < G; r = r + 1) begin
                for (c = 0; c < G; c++) begin
                    if (chain_busy[r][c]) begin
                        if (chain_timer[r][c] <= 1) begin
                            enable[r][c]     <= 0;
                            chain_busy[r][c] <= 0;
                        end else begin
                            chain_timer[r][c] <= chain_timer[r][c] - 1;
                        end
                    end
                end
            end
        end
    end
endmodule
