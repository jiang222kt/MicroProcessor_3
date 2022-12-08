`include "define.vh"

module top(
    input clk,
    input rst_n,
    input [31:0] addr,
    input [6:0] op,
    input [31:0] rd_addr,
    input [31:0] wr_addr,
    input [31:0] data_in,
    input write_enable,
    input [31:0] ir,
    output [31:0] pc,
    output [31:0] rd_data,
    output [31:0] data_out,
    output [31:0] instruction,
    output [4:0] srcreg1_num,
    output [4:0] srcreg2_num,
    output [4:0] dstreg_num,
    output [31:0] imm,
    output [5:0] alucode,
    output [1:0] aluop1_type,
    output [1:0] aluop2_type,
    output reg_we,
    output is_load,
    output is_store,
    output is_halt,
    output [31:0] alu_result,
    output br_taken
);

// プログラムカウンタ
program_counter pc_module(
    .clk(clk),
    .rst_n(rst_n),
    .addr(addr),
    .op(op),
    .pc(pc)
);

// レジスタファイル
register_file rf_module(
    .rd_addr(rd_addr),
    .wr_addr(wr_addr),
    .data_in(data_in),
    .rd_data(rd_data),
    .write_enable(write_enable)
);

// データメモリ
data_memory dm_module(
    .clk(clk),
    .addr(addr),
    .data_in(data_in),
    .data_out(data_out),
    .write_enable(write_enable)
);

// 命令メモリ
instruction_memory im_module(
    .clk(clk),
    .pc(pc),
    .instruction(instruction)
);

// デコーダ
decoder dec_module(
    .ir(ir),
    .srcreg1_num(srcreg1_num),
    .srcreg2_num(srcreg2_num),
    .dstreg_num(dstreg_num),
    .imm(imm),
    .alucode(alucode),
    .aluop1_type(aluop1_type),
    .aluop2_type(aluop2_type),
    .reg_we(reg_we),
    .is_load(is_load),
    .is_store(is_store),
    .is_halt(is_halt)
);

// ALU
alu alu_module (
    .alucode(alucode),
    .op1(op1),
    .op2(op2),
    .alu_result(alu_result),
    .br_taken(br_taken)
);

モジュカスくんさぁ