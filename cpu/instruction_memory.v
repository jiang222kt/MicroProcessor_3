module instruction_memory(
    input wire [31:0]pc, //プログラムカウンタ
    output reg [31:0] instruction
);

reg [31:0] mem [0:32'h8000];
initial $readmemh("/home/denjo/b3exp/benchmarks/Coremark_for_Synthesis/code.hex", mem);

always @(*) begin
    instruction <= mem[pc>>2];
end

endmodule