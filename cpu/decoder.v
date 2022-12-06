`include "define.vh"

module decoder(
    input  wire [31:0]  ir,           // 機械語命令列
    output wire  [4:0]	srcreg1_num,  // ソースレジスタ1番号
    output wire  [4:0]	srcreg2_num,  // ソースレジスタ2番号
    output wire  [4:0]	dstreg_num,   // デスティネーションレジスタ番号
    output wire [31:0]	imm,          // 即値
    output reg   [5:0]	alucode,      // ALUの演算種別
    output reg   [1:0]	aluop1_type,  // ALUの入力タイプ
    output reg   [1:0]	aluop2_type,  // ALUの入力タイプ
    output reg	     	reg_we,       // レジスタ書き込みの有無
    output reg		is_load,      // ロード命令判定フラグ
    output reg		is_store,     // ストア命令判定フラグ
    output reg      is_halt
);

wire [6:0] op = ir[6:0];
wire [6:0] funct7 = ir[31:25];
wire [2:0] funct3 = ir[14:12];

assign srcreg1_num = (op == `LUI || op == `AUIPC || op == `JAL)?  5'b0 : ir[19:15];
assign srcreg2_num = (op == `OP || op == `JALR || op == `STORE)? ir[24:20] : 5'b0;
assign dstreg_num = (op == `BRANCH || op == `STORE)? 5'b0 : ir[11:7];

// if(op == `OPIMM)
//     if(funct3 == 3'b000 || funct3 == 3'b101)
//         assign imm = 27'b0, ir[24:20];
//     else
//         assign imm = 20ir[31], ir[31:20];
    
// else if(op == `LUI || op == `AUIPC)
//     assign imm = ir[31:12], 12'b0;
// else if(op == `JAL)
//     assign imm = 11ir[31], ir[31],ir[19:12], ir[20], ir[30:21], 1'b0;
// else if(op == `JALR || op == `LOAD)
//     assign imm = 20ir[31], ir[31:20];
// else if(op == `STORE)
//     assign  imm = 20ir[31],ir[31:25],ir[11:7];
// else if(op == `BRANCH)
//     assign imm = 19ir[31], ir[31], ir[30:25] ,ir[11:8], ir[7], 1'b0;

assign imm = (op == `OPIMM) ? (funct3 == 3'b000 || funct3 == 3'b101) ? {27'b0, ir[24:20]} : {{20{ir[31]}}, ir[31:20]}
    : (op == `LUI || op == `AUIPC) ? {ir[31:12], 12'b0}
    : (op == `JAL) ? {{11{ir[31]}}, ir[31],ir[19:12], ir[20], ir[30:21], {1'b0}}
    : (op == `JALR || op == `LOAD) ? {{20{ir[31]}}, ir[31:20]}
    : (op == `STORE) ? {{20{ir[31]}},ir[31:25],ir[11:7]}
    : (op == `BRANCH) ? {{19{ir[31]}}, ir[31], ir[30:25] ,ir[11:8], ir[7], {1'b0}}
    : 0;

always @(*) begin
    if (op == `OPIMM)
        if(funct3 == 3'b000)
            alucode <= `ALU_ADD;
        else if(funct3 == 3'b010)
            alucode <= `ALU_SLT;
        else if(funct3  == 3'b011)
            alucode <= `ALU_SLTU;
        else if(funct3 == 3'b100)
            alucode <= `ALU_XOR;
        else if(funct3 == 3'b110)
            alucode <= `ALU_OR;
        else if(funct3 == 3'b111)
            alucode <= `ALU_AND;
        else if(funct3 == 3'b001)
            alucode <= `ALU_SLL;
        else if(funct3 == 3'b101 && funct7 == 7'b0000000)
            alucode <= `ALU_SRL;
        else if(funct3 == 3'b101 && funct7 == 7'b0100000)
            alucode <= `ALU_SRA;
        else
            alucode <=  `ALU_NOP;
        
    else if(op == `OP)
        if(funct3 == 3'b000 && funct7 == 7'b0000000)
            alucode <= `ALU_ADD;
        else if(funct3 == 3'b000 && funct7 == 7'b0100000)
            alucode <= `ALU_SUB;
        else if(funct3 == 3'b001)
            alucode <= `ALU_SLL;
        else if(funct3 == 3'b010)
            alucode <= `ALU_SLT;
        else if(funct3 == 3'b011)
            alucode <= `ALU_SLTU;
        else if(funct3 == 3'b100)
            alucode <= `ALU_XOR;
        else if(funct3 == 3'b101 && funct7 == 7'b0000000)
            alucode <= `ALU_SRL;
        else if(funct3 == 3'b101 && funct7 == 7'b0100000)
            alucode  <= `ALU_SRA;
        else if(funct3 == 3'b110)
            alucode  <= `ALU_OR;
        else if(funct3 == 3'b111)
            alucode <= `ALU_AND;
        else
            alucode <= `ALU_NOP;
        
    else if(op == `BRANCH)
        if(funct3 == 3'b000)
            alucode <= `ALU_BEQ;
        else if(funct3 == 3'b001)
            alucode  <=  `ALU_BNE;
        else if(funct3 == 3'b100)
            alucode <= `ALU_BLT;
        else if(funct3 == 3'b101)
            alucode <= `ALU_BGE;
        else if(funct3 == 3'b110)
            alucode <= `ALU_BLTU;
        else if(funct3 == 3'b111)
            alucode <= `ALU_BGEU;
        else
            alucode <= `ALU_NOP;
        
    else if(op == `STORE)
        if(funct3 == 3'b000)
            alucode <= `ALU_SB;
        else if(funct3 == 3'b001)
            alucode <= `ALU_SH;
        else if(funct3 == 3'b010)
            alucode <= `ALU_SW; 
        else
            alucode <= `ALU_NOP;
        
    else if(op == `LOAD)
        if(funct3 == 3'b000)
            alucode <= `ALU_LB;
        else if(funct3 == 3'b001) 
            alucode <= `ALU_LH;
        else if(funct3 == 3'b10) 
            alucode <= `ALU_LW;
        else if(funct3 == 3'b100) 
            alucode <= `ALU_LBU;
        else if(funct3 == 3'b101) 
            alucode <= `ALU_LHU;
        else
            alucode <= `ALU_NOP;
        
    else if(op == `LUI)
        alucode <= `ALU_LUI;
    else if(op == `AUIPC)
        alucode <= `ALU_ADD;
    else if(op == `JAL)
        alucode <= `ALU_JAL;
    else if(op == `JALR)
        alucode <= `ALU_JALR;
    else
        alucode <= `ALU_NOP;

    aluop1_type <= (op == `OP || op == `OPIMM || op == `STORE || op == `LOAD || op == `JAL || op == `JALR) ? `OP_TYPE_REG : (op == `BRANCH)? `OP_TYPE_PC : (op == `AUIPC)? `OP_TYPE_IMM : `OP_TYPE_NONE; 
    aluop2_type <= (op == `OP)? `OP_TYPE_REG : (op == `OPIMM || op == `STORE || op == `LOAD || op == `BRANCH || op == `JAL || op == `JALR) ? `OP_TYPE_IMM : (op == `AUIPC)? `OP_TYPE_PC : (op == `LUI)? `OP_TYPE_IMM : `OP_TYPE_NONE;
    is_load <= (op == `LOAD)? funct3: 3'b111; // 3'b111がないから使ったけど大丈夫か？
    is_store <= (op == `STORE)? funct3 : 3'b111;
    reg_we <= (op == `OP || op == `OPIMM || op == `LUI || op == `AUIPC || op == `LOAD || (op == `JAL && dstreg_num != 5'b0) || (op == `JALR && dstreg_num != 5'b0))? 1'b1 : 1'b0;

end
endmodule
