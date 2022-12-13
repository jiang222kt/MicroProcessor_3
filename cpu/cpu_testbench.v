module cpu_tb;
    reg clk;
    reg rst_n;

    parameter CYCLE = 100;

    always #(CYCLE/2) clk = ~clk;

    cpu cpu0(
       .clk(clk),
       .rst_n(rst_n)
    );

    initial begin
        #10     clk     = 1'd0;
                rst_n    = 1'd0;
        #(CYCLE) rst_n = 1'd1;
        #(10000) $finish;
    end
endmodule
