`include "define.vh"

module top(
    input wire clk,
    input wire cpu_rst,
    output wire uart_rx_out
);

// wire and reg
//decoder
reg [31:0] ir;
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
reg [5:0] alucode;
wire [31:0] op1;
wire [31:0] op2;
wire [31:0] alu_result;
wire br_taken;

wire [31:0] addr;
wire [31:0] data_in;
wire [31:0] data_out;
wire [3:0] write_enable;

wire [31:0] r1_data;
wire [31:0] r2_data;
wire [31:0] r1_addr;
wire [31:0] r2_addr;
wire [4:0] wr_addr;
wire [31:0] reg_data_in;
wire reg_write_enable;

wire [31:0] inst_pc;
wire [31:0] instruction;

// プログラムカウンタ
program_counter program_counter0(
    .clk(clk),
    .rst_n(rst_n),
    .addr(addr),
    .op(op),
    .pc(pc)
);

// レジスタファイル
register_file register_file0(
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
    .data_in(data_in), 
    .data_out(data_out), 
    .write_enable(write_enable) 
);
 
// 命令メモリ
instruction_memory instruction_memory0(
    .clk(clk),
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
    .is_store(is_store), 
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
assign uart_IN_data = ma_store_value_raw[7:0];  // ストアするデータをモジュールへ入力
assign uart_we = ((ma_ldst_addr == `UART_ADDR) && (ma_is_store == `ENABLE)) ? 1'b1 : 1'b0;  // シリアル通信用アドレスへのストア命令実行時に送信開始信号をアサート
assign uart_tx = uart_OUT_data;  // シリアル通信モジュールの出力はFPGA外部へと出力


//hardware_counter
wire [31:0] hc_OUT_data;
hardware_counter hardware_counter0(
    .CLK_IP(clk),
    .RSTN_IP(rst_n),
    .COUNTER_OP(hc_OUT_data)
);

assign uart_IN_data = ma_store_value_raw[7:0];  // ストアするデータをモジュールへ入力
assign uart_we = ((ma_ldst_addr == `UART_ADDR) && (ma_is_store == `ENABLE)) ? 1'b1 : 1'b0;  // シリアル通信用アドレスへのストア命令実行時に送信開始信号をアサート
assign uart_tx = uart_OUT_data;  // シリアル通信モジュールの出力はFPGA外部へと出力
assign ma_load_value =  ((ma_alucode == `ALU_LW) && (ma_ldst_addr == `HARDWARE_COUNTER_ADDR)) ? hc_OUT_data : ${データメモリから読んできた値};


endmodule