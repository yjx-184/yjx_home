module light(
  input clk,                //时钟信号
  input rst,                //复位信号
  output reg [15:0] led     //LED灯
);
  reg [31:0] count;         //计数器
  
  //时钟上升沿触发
  always @(posedge clk) begin
    //rst为高电平时，led置为1，计数器清零
    if (rst) begin 
        led <= 1; 
        count <= 0; 
    end
    else begin
        //如果计数器为0,则led向左移，最高位led[15]变为最低位
      if (count == 0) led <= {led[14:0], led[15]};
      //如果计数器达到5000000则重置，否则继续自增+1
      count <= (count >= 5000000 ? 32'b0 : count + 1);
    end
  end
endmodule