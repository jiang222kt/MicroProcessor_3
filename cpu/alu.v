`include "define.vh"

module alu(
    input wire [5:0] alucode,       // 演算種別
    input wire [31:0] op1,          // 入力データ1
    input wire [31:0] op2,          // 入力データ2
    output reg [31:0] alu_result,   // 演算結果
    output reg br_taken             // 分岐の有無
);

always @(*) begin
    br_taken = `DISABLE;
    if(alucode == `ALU_ADD || alucode == `ALU_LB || alucode == `ALU_LH || alucode == `ALU_LW || alucode == `ALU_LBU || alucode == `ALU_LHU || alucode == `ALU_SB || alucode == `ALU_SH) begin
        alu_result <= op1 + op2;
    end
    else if(alucode == `ALU_SUB) begin
        alu_result <= op1 - op2;
    end
    else if(alucode == `ALU_LUI) begin 
        alu_result <= 32'b0;
    end
    else if(alucode == `ALU_JAL) begin
        alu_result <= op2 + 4;
        br_taken   <= `ENABLE;
    end
    else if(alucode == `ALU_JALR) begin
        alu_result = op2 + 4;
        br_taken   <= `ENABLE;
    end
    else if(alucode == `ALU_SLT) begin
        alu_result <= (($signed(op1) < $signed(op2))? {{31'b0}, {1'b1}}: 32'b0);
    end
    else if(alucode == `ALU_SLTU) begin
        alu_result <= (($unsigned(op1) < $unsigned(op2))? {{31'b0}, {1'b1}}: 32'b0);
    end
    else if(alucode == `ALU_XOR) begin
        alu_result <= op1 ^ op2;
    end
    else if(alucode == `ALU_OR) begin
        alu_result <= op1 | op2;
    end
    else if(alucode == `ALU_AND) begin
        alu_result <= op1 & op2;
    end
    else if(alucode == `ALU_SLL) begin
        alu_result <= (op1 << op2[4:0]);
    end
    else if(alucode == `ALU_SRL) begin
        alu_result <= (op1 >> op2[4:0]);
    end
    else if(alucode == `ALU_SRA) begin
        alu_result <= ($signed(op1) >>> op2[4:0]);
    end
    else if(alucode == `ALU_BEQ) begin
        alu_result <= 32'b0;
    end
    else if(alucode == `ALU_BNE) begin
        alu_result <= 32'b0;
    end
    else if(alucode == `ALU_BLT) begin
        alu_result <= 32'b0;
    end
    else if(alucode == `ALU_BGE) begin
        alu_result <= 32'b0;
    end
    else if(alucode == `ALU_BLTU) begin
        alu_result <= 32'b0;
    end
    else if(alucode == `ALU_BGEU) begin
        alu_result <= 32'b0;
    end
    else begin
        alu_result = 32'b0;
    end
    end
endmodule