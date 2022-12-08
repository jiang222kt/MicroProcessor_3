module data_memory(
  input clk,
  input [31:0] addr,
  input [31:0] data_in,
  output reg [31:0] data_out,
  input write_enable
);

reg [31:0] mem [0:100000];
initial $readmemh("/home/denjo/b3exp/benchmarks/tests/LoadAndStore/code.hex", mem);

// データを書き込む処理
always @ (posedge clk) begin
  if (write_enable) begin
    mem[addr] <= data_in;
  end
end

// データを読み出す処理
always @ (posedge clk) begin
  data_out <= mem[addr];
end

endmodule
