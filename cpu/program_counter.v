`include "define.vh"

module program_counter(
  input clk,
  input rst_n,
  input [31:0] addr,
  input [6:0] op,
  output [31:0] pc
);

  reg [31:0] pc_reg;

  // クロックとリセット信号の処理
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      // リセット時の処理
      pc_reg <= 0;
    end else begin
        if (op == `BRANCH) //分岐命令の場合
            pc_reg <= addr;
        else               //その他のとき
            pc_reg <= pc_reg + 1;
    end
  end

  assign pc = pc_reg;

endmodule
