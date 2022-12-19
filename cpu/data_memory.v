`include "define.vh"
module data_memory(
  input clk,
  input [31:0] addr,
  input [31:0] data_in,
  input [5:0] alucode,
  output reg [31:0] data_out,
  input write_enable,
  input wire is_load,
  input wire is_store
);

reg [31:0] mem [0:32'h8000];
wire [31:0] current_addr;
assign current_addr = addr>>2;
initial $readmemh("/home/denjo/b3exp/benchmarks/Coremark_for_Synthesis/data.hex", mem);

wire [4:0]count;
assign count = (addr[1:0] == 3)?24: (addr[1:0] == 2)? 16: (addr[1:0] == 1)?8:0;

// データを書き込む処理
always @ (posedge clk) begin
  if (is_store) begin
    if(alucode == `ALU_SB) begin
      mem[current_addr][count+7-:8] <= data_in[7:0];
    end
    else if(alucode  <= `ALU_SH) begin
      mem[current_addr][count+15-:16] <= data_in[15:0];
    end
    else if(alucode == `ALU_SW)begin
      mem[current_addr] <= data_in;
    end
  end
end

// データを読み出す処理
always @ (*) begin
  if(is_load) begin
    if(alucode == `ALU_LB) begin
      data_out <= {{24{mem[current_addr][count + 7]}}, mem[current_addr][count+7-:8]};
    end
    else if(alucode == `ALU_LH) begin
      data_out <= {{16{mem[current_addr][count + 15]}}, mem[current_addr][count+15-:16]};
    end
    else if(alucode == `ALU_LBU) begin
      data_out <= {{24'b0}, mem[current_addr][count+7-:8]};
    end
    else if(alucode == `ALU_LHU) begin
      data_out <= {{16'b0}, mem[current_addr][count+15-:16]};
    end
    else if(alucode == `ALU_LW) begin
      data_out <= mem[current_addr];
    end
    else begin
      data_out <= 32'b0;
    end
  end
  else begin
    data_out <= 32'b0;
  end
end

endmodule