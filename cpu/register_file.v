module register_file(
  input clk,
  input [31:0] rd_addr, //読み出しアドレス
  input [31:0] wr_addr, //書き込みアドレス
  input [31:0] data_in, //データ
  output reg [31:0] rd_data, //レジスタファイルから読み出されたデータ
  input write_enable
);

reg [31:0] regs [0:100000];

// レジスタを書き込む処理
always @ (posedge clk) begin
  if (write_enable) begin
    regs[wr_addr] <= data_in;
  end
end

// レジスタを読み出す処理
always @ (posedge clk) begin
  rd_data <= regs[rd_addr];
end

endmodule
