`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.06.2021 19:26:13
// Design Name: 
// Module Name: SA4_CACHE
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


module SA4_CACHE(
input clk,                //ʱ��
input rst,                //��λ�źţ��͵�ƽ��Ч
input [31:0] address
    );    

reg not_valid;
reg[1:0] least_set;		//LRU�㷨��ɺ���Զ�����
reg[7:0] temp;			//����LRU�㷨ʱ����ʱ�Ĵ���
reg[7:0] count;			//��ǰ��ѯ�ı�ţ�����LRU�㷨
reg[15:0] miss;			//δ����
reg[15:0] hit;			//����
reg[15:0]     w_addr;      //RAM PORT A д��ַ
reg[91:0]    w_data;     //RAM PORT  A д����
reg          ena;        //RAMʹ�ܣ��ߵ�ƽ��Ч
reg          wea;        //RAM PORT  A дʹ�ܣ��ߵ�ƽ��Ч
reg          enb;        //RAM PORT  B ��ʹ�ܣ��ߵ�ƽ��Ч
reg[15:0]     r_addr;     //RAM PORT  B ����ַ
wire[91:0]   r_data;    //RAM PORT   B ������

//4·������ӳ�仺��
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
		  count <= 8'd0;
		  temp <= 8'd0;
		  least_set <= 2'b0;
		  not_valid <= 1'b0;
	  end
      else begin
		  	least_set <= 2'b0;
		    ena <= 1'b1;
		  	enb <= 1'b1;
			r_addr <= address[17:2];			//����Index��������������
			if(r_data[91]==1 && r_data[82:69]==address[31:18])	//ƥ�䵽��һ��������Ч����tag����ͬ
			begin
				hit<=hit+1'b1;
				w_data<=r_data;
				w_data[90:83]<=count;		//���±�ʹ��
				w_addr<=address[17:2];		//Index
				wea <= 1'b1;
			end
			else
			begin
				if (r_data[91]==0)			//�������Чλֱ���滻
				begin
					not_valid <= 1'b1;
				end
				else
				begin
					temp <= r_data[90:83];
				end

				if(r_data[68]==1 && r_data[59:46]==address[31:18])	//ƥ�䵽�ڶ���������Ч����tag����ͬ
				begin
					hit<=hit+1'b1;
					w_data<=r_data;
					w_data[67:60]<=count;		//���±�ʹ��
					w_addr<=address[17:2];		//Index
					wea <= 1'b1;
				end
				else
				begin
					if (r_data[68]==0)			//�������Чλֱ���滻
					begin
						not_valid <= 1'b1;
						least_set <= 2'b1;
					end
					else
					begin
						if(not_valid == 0 && temp > r_data[67:60])	// LRUѰ����Զ���ʹ�����
						begin
							least_set <= 2'b1;
							temp <= r_data[67:60];
						end
					end

					if(r_data[45]==1 && r_data[36:23]==address[31:18])	//ƥ�䵽������������Ч����tag����ͬ
					begin
						hit<=hit+1'b1;
						w_data<=r_data;
						w_data[44:37]<=count;		//���±�ʹ��
						w_addr<=address[17:2];		//Index
						wea <= 1'b1;
					end
					else
					begin
						if (r_data[45]==0)			//�������Чλֱ���滻
						begin
							not_valid <= 1'b1;
							least_set <= 2'b10;
						end
						else
						begin
							if(not_valid == 0 && temp > r_data[44:37])	// LRUѰ����Զ���ʹ�����
							begin
								least_set <= 2'b10;
								temp <= r_data[44:37];
							end
						end

						if(r_data[22]==1 && r_data[13:0]==address[31:18])	//ƥ�䵽������������Ч����tag����ͬ
						begin
							hit<=hit+1'b1;
							w_data<=r_data;
							w_data[21:14]<=count;		//���±�ʹ��
							w_addr<=address[17:2];		//Index
							wea <= 1'b1;
						end
						else
						begin
							if (r_data[22]==0)			//�������Чλֱ���滻
							begin
								not_valid <= 1'b1;
								least_set <= 2'b11;
							end
							else
							begin
								if(not_valid == 0 && temp > r_data[21:14])	// LRUѰ����Զ���ʹ�����
								begin
									least_set <= 2'b11;
								end
							end
							w_data<=r_data;
							//ȫ��δ���У������滻
							case(least_set)
								2'b0:
								begin
									w_data[91]<=1;				//��Чλ��Ϊ1
									w_data[90:83]<=count;		//���±�ʹ��
									w_data[82:69]<=address[31:18];//Tag
								end
								2'b1:
								begin
									w_data[68]<=1;				//��Чλ��Ϊ1
									w_data[67:60]<=count;		//���±�ʹ��
									w_data[59:46]<=address[31:18];//Tag
								end
								2'b10:
								begin
									w_data[45]<=1;				//��Чλ��Ϊ1
									w_data[44:37]<=count;		//���±�ʹ��
									w_data[36:23]<=address[31:18];//Tag
								end
								2'b11:
								begin
									w_data[22]<=1;				//��Чλ��Ϊ1
									w_data[21:14]<=count;		//���±�ʹ��
									w_data[13:0]<=address[31:18];//Tag
								end
							endcase
							w_addr<=address[17:2];		//Index
							wea <= 1'b1;
							miss<=miss+1'b1;
						end
					end
				end
			end
			count<=count+1'b1;					//LRU����
	  end 
end 

////////////////////////////////////////////////
//ʵ����RAM 
blk_mem_gen_0 ram_ip_test ( 
  .clka      (clk          ),            // input clka 
  .ena       (ena          ),            // input [1 : 0] ena 
  .wea       (wea          ),            // input [1 : 0] wea 
  .addra     (w_addr       ),            // input [16 : 0] addra 
  .dina      (w_data       ),            // input [92 : 0] dina 
   .clkb     (clk          ),            // input clkb 
   .enb      (enb          ),			 // input [1 : 0] ena 
   .addrb    (r_addr       ),            // input [16 : 0] addrb 
   .doutb    (r_data       )             // output [92 : 0] doutb 
  ); 

endmodule
