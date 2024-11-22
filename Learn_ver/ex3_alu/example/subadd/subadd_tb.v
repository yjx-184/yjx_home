`timescale 1ns / 1ps

module subadd_tb;

    //输入信号
    reg signed [4:0] i, j;          //测试输入，扩展为5位以检测溢出
    reg inputaluop;                 //控制信号，加法0,减法1
    reg [3:0] inputa, inputb;       //加法器的输入

    //输出信号
    wire [3:0] outputs;             //输出结果
    wire resultc, resultof, resultz;//进位，溢出，零标志位

    //预期结果
    reg [4:0] k;                    //计算结果扩展为5位
    reg of, c, z;                   //预期的溢出，进位，零位

    //实例化
    subadd uut (
        .a(inputa),
        .b(inputb),
        .cin(inputaluop),
        .carry(resultc),
        .overflow(resultof),
        .zero(resultz)
    );

    //错误计数器
    integer errors = 0;

    //测试任务
    task check;
        input [3:0] results;        //alu的结果预期正确输出
        input resultof, resultc, resultz;   //alu的预期溢出，进位，零位
        begin
            //比较预期结果和测试单元输出的outputs
            if(outputs != results)  
                begin
                    $display("Error:a = %h, b = %h, ctrl = %b,sum should be %h,get %h\n", inputa, inputb, inputaluop, results, outputs);
                    errors = errors + 1;
                end

            //比较预期溢出和测试单元溢出的resultof
            if(resultof != of)
                begin
                    $display("overflow Error:a = %h, b = %h, ctrl = %b,overflow should be %b,get %b\n", inputa, inputb, inputaluop, of, resultof);
                    errors = errors + 1; 
                end

            //比较预期进位和测试单元进位的resultc
            if(resultc != c)
                begin
                    $display("carry Error:a = %h, b = %h, ctrl = %b,carry should be %b, get %b\n",inputa, inputb, inputaluop, c, resultc);
                    errors = errors + 1; 
                end

            //比较预期零位和测试单元零位的resultz
            if(resultz != z)
                begin
                    $display("zero Error:a = %h, b = %h,ctrl = %b, zero should be %b,get %b\n",inputa, inputb, inputaluop, z, resultz);
                    errors = errors + 1; 
                end
        end
        endtask

        //测试流程
        initial begin
            $display("开始测试subadd.v ......\n");

            //遍历
            for(i = -8; i <= 7; i = i+1)
            begin
                for(j = -8; j <= 7; j = j+1)
                begin
                    inputa = i[3:0];
                    inputb = j[3:0];            //设置两个输入
                    inputaluop = 4'b0000;       //alu的操作码
                    k = i + j;                  //计算加法预期结果
                    of = ((i[3] == j[3]) && (k[4] != k[3]));    //溢出检测
                    z = (k[3:0] == 0);          //零位
                    c = (k[4] == 1);            //进位
                    #20 check(k[3:0],of,c,z);
                end
        end

        //显示测试结果
        if (errors == 0) begin
            $display("所有测试通过，没有出错！");
        end else begin
            $display("有%d个错误", errors);
        end
        $stop;
        end
    endmodule
