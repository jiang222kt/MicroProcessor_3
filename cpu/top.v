`include "define.vh"

module cpu(
    input wire clk,
    input wire rst_n,
    output wire uart_tx//uart_rx_out
);

// wire and reg
wire [31:0] ma_load_value;
//decoder
wire [31:0] ir;
wire  [4:0] srcreg1_num;
wire  [4:0] srcreg2_num;
wire  [4:0] dstreg_num;
wire [31:0] imm;
wire  [5:0] dec_alucode;
wire  [1:0] aluop1_type;
wire  [1:0] aluop2_type;
wire reg_we;
wire is_load;
wire is_store;
//alu
wire [5:0] alucode;
wire [31:0] op1;
wire [31:0] op2;
wire [31:0] alu_result;
wire br_taken;
//data_mem
wire [31:0] addr;
wire [31:0] data_in;
wire [31:0] data_out;
wire [5:0] data_alucode;
wire write_enable;
wire data_is_store;
wire data_is_load;
//register
wire [31:0] r1_data;
wire [31:0] r2_data;
wire [4:0] r1_addr;
wire [4:0] r2_addr;
wire [4:0] wr_addr;
wire [31:0] reg_data_in;
wire reg_write_enable;
// isntruction memory
wire [31:0] inst_pc;
wire [31:0] instruction;
//program counter
wire [31:0] pc_addr;
reg [31:0] pc;
wire [31:0] next_pc;

// プログラムカウンタ
program_counter program_counter0(
    .pc(pc),
    .br_taken(br_taken),
    .addr(pc_addr),
    .next_pc(next_pc)
);

// レジスタファイル
register_file register_file0(
    .clk(clk),
    .r1_addr(r1_addr), 
    .r2_addr(r2_addr), 
    .wr_addr(wr_addr), 
    .data_in(reg_data_in), 
    .r1_data(r1_data), 
    .r2_data(r2_data), 
    .write_enable(reg_write_enable) 
);

// データメモリ
data_memory data_memory0(
    .clk(clk), 
    .addr(addr), 
    .alucode(data_alucode),
    .data_in(data_in), 
    .data_out(data_out), 
    .write_enable(write_enable),
    .is_store(data_is_store),
    .is_load(data_is_load)
);
 
// 命令メモリ
instruction_memory instruction_memory0(
    .pc(inst_pc), 
    .instruction(instruction) 
);

// デコーダ
decoder decoder0(
    .ir(ir),
    .srcreg1_num(srcreg1_num), 
    .srcreg2_num(srcreg2_num), 
    .dstreg_num(dstreg_num), 
    .imm(imm), 
    .alucode(dec_alucode), 
    .aluop1_type(aluop1_type), 
    .aluop2_type(aluop2_type), 
    .reg_we(reg_we), 
    .is_load(is_load), 
    .is_store(is_store)
);

// ALU
alu alu0(
    .alucode(alucode),
    .op1(op1),
    .op2(op2),
    .alu_result(alu_result),
    .br_taken(br_taken)
);

// uart
wire [7:0] uart_IN_data;
wire uart_we;
wire uart_OUT_data;

uart uart0(
    .uart_tx(uart_OUT_data),
    .uart_wr_i(uart_we),
    .uart_dat_i(uart_IN_data),
    .sys_clk_i(clk),
    .sys_rstn_i(rst_n)
);

// Memory Accessステージに以下のような記述を追加
assign uart_IN_data = data_in[7:0];  // ストアするデータをモジュールへ入力
assign uart_we = ((addr == `UART_ADDR) && (is_store == `ENABLE)) ? 1'b1 : 1'b0;  // シリアル通信用アドレスへのストア命令実行時に送信開始信号をアサート
assign uart_tx = uart_OUT_data;  // シリアル通信モジュールの出力はFPGA外部へと出力

//hardware_counter
wire [31:0] hc_OUT_data;
hardware_counter hardware_counter0(
    .CLK_IP(clk),
    .RSTN_IP(rst_n),
    .COUNTER_OP(hc_OUT_data)
);

assign ma_load_value =  ((alucode == `ALU_LW) && (addr == `HARDWARE_COUNTER_ADDR)) ? hc_OUT_data : data_out;

assign inst_pc = pc;
assign ir = instruction;
assign r1_addr = srcreg1_num;
assign r2_addr = srcreg2_num;

assign op1 = (aluop1_type == `OP_TYPE_REG)? r1_data:(aluop1_type == `OP_TYPE_IMM)?imm :32'h0;
assign op2 = (aluop2_type == `OP_TYPE_REG)? r2_data:(aluop2_type == `OP_TYPE_IMM)?imm :(aluop2_type == `OP_TYPE_PC)?pc:32'h0;

assign alucode = dec_alucode;
assign data_in = r2_data;
assign wr_addr = dstreg_num;
assign reg_data_in = (is_load)? ma_load_value:alu_result;
assign write_enable =(is_store)?1'b1:1'b0;
assign reg_write_enable = reg_we;
assign pc_addr = (alucode ==  `ALU_JALR)? r1_data + imm : pc + imm;
assign addr = alu_result;
assign data_alucode = alucode;
assign data_is_load = is_load;
assign data_is_store = is_store;

always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        pc <= 32'h8000;
    end
    else begin
        pc <= next_pc;
    end
end

endmodule