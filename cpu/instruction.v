module instruction(
    input wire [31:0] PC,
    output reg [31:0] instruction
);

reg [31:0] mem [0:100000];
initial $readmemh("/home/denjo/b3exp/benchmarks/tests/LoadAndStore/code.hex", mem);

always @(*) begin
    instruction <= mem[PC];
end

endmodule
