`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.06.2021 11:32:42
// Design Name: 
// Module Name: DM_CACHE
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module DM_CACHE(
input clk,                //ʱ��
input rst,                //��λ�źţ��͵�ƽ��Ч
input [31:0] address
    );    

reg[15:0] miss;			//δ����
reg[15:0] hit;			//����
reg[15:0]     w_addr;      //RAM PORT A д��ַ
reg[14:0]    w_data;     //RAM PORT  A д����
reg          ena;        //RAMʹ�ܣ��ߵ�ƽ��Ч
reg          wea;        //RAM PORT  A дʹ�ܣ��ߵ�ƽ��Ч
reg          enb;        //RAM PORT  B ��ʹ�ܣ��ߵ�ƽ��Ч
reg[15:0]     r_addr;     //RAM PORT  B ����ַ
wire[14:0]   r_data;    //RAM PORT   B ������

//ȫ����ӳ�仺��
always@(posedge clk or negedge rst) begin
      if(!rst) begin  //���������ֵ
		  ena <= 1'b0;
		  enb <= 1'b0;
		  r_addr <= 16'd0;
		  wea <= 1'b0;
	      w_addr <= 16'd0;
		  w_data <= 15'd0;
		  miss <= 16'd0;
		  hit <= 16'd0;
	  end
      else begin
		    ena <= 1'b1;
		  	enb <= 1'b1;
			r_addr <= address[17:2];			//����Index��������������
			if(r_data[14]==0)					//������Ч���Զ�ģ����ڴ�װ������
			begin
				w_data[14]<=1;					//��Чλ��Ϊ1
				w_data[13:0]<=address[31:18];	//Tag
				w_addr<=address[17:2];		//Index
				miss<=miss+1'b1;					//δ����
				wea <= 1'b1;
			end
			else
			begin
				if(r_data[13:0]==address[31:18]) //������Ч����tag����ͬ
				begin	
					hit<=hit+1'b1;					//����
				end
				else
				begin							//������Ч��δװ�룬ֱ���滻װ��
					w_data[14]<=1;					//��Чλ
					w_data[13:0]<=address[31:18];	//Tag
					w_addr <= address[17:2];		//Index
					miss<=miss+1'b1;				//δ����
					wea <= 1'b1;
				end
			end
	  end 
end 

////////////////////////////////////////////////
//ʵ����RAM 
blk_mem_gen_0 ram_ip_test ( 
  .clka      (clk          ),            // input clka 
  .ena       (ena          ),            // input [1 : 0] ena 
  .wea       (wea          ),            // input [1 : 0] wea 
  .addra     (w_addr       ),            // input [16 : 0] addra 
  .dina      (w_data       ),            // input [15 : 0] dina 
   .clkb     (clk          ),            // input clkb 
   .enb      (enb          ),			 // input [1 : 0] ena 
   .addrb    (r_addr       ),            // input [16 : 0] addrb 
   .doutb    (r_data       )             // output [15 : 0] doutb 
  ); 

endmodule
