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
assign imm = (op == `)


always @(*) begin
    case (op)
        `OPIMM : begin
            case (funct3)
                3'b000 : begin
                    alucode = `ALU_ADD;
                end
                3'b001 : begin
                    alucode = `ALU_SLL;
                end
                3'b010 : begin
                    alucode = `ALU_SLT;
                end
                3'b011 : begin 
                    alucode = `ALU_SLTU;
                end
                3'b100 : begin
                    alucode = `ALU_XOR;
                end
                3'b101 : begin
                    alucode = `
    
endmodule
