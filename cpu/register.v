module register_8(reg_e, rst, reg_in, reg_out);
	input 		reg_e;
	input 		rst;
	input	[7:0] reg_in;
	output	[7:0] reg_out;
	reg	[7:0] reg_out;
	
	always @(posedge reg_e or negedge rst) begin
		if(rst == 1'b0)
			reg_out	<= 8'b00000000;
		else
			reg_out	<= reg_in;
	end
	
endmodule