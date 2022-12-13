`include "define.vh"

module program_counter(
  input [31:0] pc,
  input [31:0] addr,
  input br_taken,
  output [31:0] next_pc //next pc
);


assign next_pc = (br_taken)? addr:pc + 4;


endmodule
