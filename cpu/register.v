module register_file(
  input [31:0] rd_addr, //読み出しアドレス
  input [31:0] wr_addr, //書き込みアドレス
  input [31:0] data_in, //データ
  output [31:0] rd_data, //レジスタファイルから読み出されたデータ
  input write_enable
);

  // レジスタを定義
  reg [31:0] regs [0:100000];

  // 初期化データをロードする
  initial $readmemh("/home/denjo/b3exp/benchmarks/tests/LoadAndStore/code.hex", regs);

  // レジスタを書き込む処理
  always @ (wr_addr, write_enable, data_in) begin
    if (write_enable) begin
      regs[wr_addr] <= data_in;
    end
  end

  // レジスタを読み出す処理
  always @ (rd_addr) begin
    rd_data <= regs[rd_addr];
  end

endmodule
