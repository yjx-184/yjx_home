`timescale 1ns / 1ps

module tb_Branch_Cond;
    //接口信号
    reg [2:0] Branch;
    reg Less;
    reg Zero;
    wire PCAsrc;
    wire PCBsrc;

    //实例化被测试模块
    Branch_Cond uut(
        .Branch(Branch),
        .Less(Less),
        .Zero(Zero),
        .PCAsrc(PCAsrc),
        .PCBsrc(PCBsrc)
    );

    //测试逻辑
    initial begin
        
        //Branch 000
        Branch = 3'b000;
        #10;
        $display("Test 1:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        //Branch 001
        Branch = 3'b001;
        #10;
        $display("Test 2:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        //Branch 010
        Branch = 3'b010;
        #10;
        $display("Test 3:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc); 

        //Branch 100
        Branch = 3'b100; Zero = 1'b0;
        #10;
        $display("Test 4:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        Branch = 3'b100; Zero = 1'b1;
        #10;
        $display("Test 5:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        //Branch 101
        Branch = 3'b101; Zero = 1'b0;
        #10;
        $display("Test 6:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        Branch = 3'b101; Zero = 1'b1;
        #10;
        $display("Test 7:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        //Branch 110
        Branch = 3'b110; Less = 1'b0;
        #10;
        $display("Test 8:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        Branch = 3'b110; Less = 1'b1;
        #10;
        $display("Test 9:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        //Branch 111
        Branch = 3'b111; Less = 1'b0;
        #10;
        $display("Test 10:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);

        Branch = 3'b111; Less = 1'b1;
        #10;
        $display("Test 11:   Branch: %b, Less = %b, Zero = %b, PCAsrc = %b, PCBsrc = %b", 
                            Branch, Less, Zero, PCAsrc, PCBsrc);






    end


endmodule