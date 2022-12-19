`include "define.vh"

module register_file(
  input clk,
  input [4:0] r1_addr, r2_addr, //読み出しアドレス
  input [4:0] wr_addr, //書き込みアドレス
  input [31:0] data_in, //データ
  output [31:0] r1_data, r2_data, //レジスタファイルから読み出されたデータ
  input write_enable
);

// レジスタを定義
reg [31:0] regs [0:31];

integer i;
initial begin
    for(i=0;i<32;i=i+1)
        regs[i]=0;
end

// レジスタを書き込む処理
always @ (posedge clk) begin
  if (write_enable == `ENABLE && wr_addr != 5'b0) begin
    regs[wr_addr] <= data_in;
  end
end

// レジスタを読み出す処理
assign r1_data = regs[r1_addr];
assign r2_data = regs[r2_addr];

endmodule
