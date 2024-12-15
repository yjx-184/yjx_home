module Data_Mem(
    input [31:0] Addr,
    input [2:0] MemOp,
    input [31:0] DataIn,
    input WrEn,
    input RdClk,
    input WrClk,
    input clrn,
    output reg [31:0] DataOut
);

    //内存数组（假设内存大小为 256 条指令，每条指令32位宽）
    reg [31:0] mem_array [1:0];

    

    //读取操作
    always @(posedge RdClk) begin
        case (MemOp)
            //读取字
            3'b000: DataOut <= mem_array[Addr[31:2]];

            //读取半字
            3'b001: begin
                case(Addr[1:0])

                    //从低地址读取半字
                    2'b00: DataOut <= {16'b0, mem_array[Addr[31:2]][15:0]};

                    //从高地址读取半字
                    2'b10: DataOut <= {16'b0, mem_array[Addr[31:2]][31:16]};

                    //无效地址
                    default: DataOut <= 32'b0;
                endcase
            end

            //读取字
            3'b010: DataOut <= mem_array[Addr[31:2]];


            //读取无符号字节
            3'b100: begin
                case(Addr[1:0])

                    //低字节
                    2'b00: DataOut <= {24'b0, mem_array[Addr[31:2]][7:0]};

                    //第二字节
                    2'b01: DataOut <= {24'b0, mem_array[Addr[31:2]][15:8]};

                    //第三字节
                    2'b10: DataOut <= {24'b0, mem_array[Addr[31:2]][23:16]};

                    //高字节
                    2'b11: DataOut <= {24'b0, mem_array[Addr[31:2]][31:24]};

                    //无效地址
                    default: DataOut <= 32'b0;
                endcase
            end

            //读取无符号半字
            3'b101: begin
                case(Addr[1:0])

                    //从低地址读取半字
                    2'b00: DataOut <= {16'b0, mem_array[Addr[31:2]][15:0]};

                    //从高地址读取半字
                    2'b10: DataOut <= {16'b0, mem_array[Addr[31:2]][31:16]};

                    //无效地址
                    default: DataOut <= 32'b0;
                endcase
            end
            //默认值
            default: DataOut <= 32'b0;
        endcase
    end

    // 写操作
    always @(negedge WrClk or negedge clrn) begin
        if (clrn == 1'b0) begin
            // 清空内存数组
            mem_array[0] <= 32'b0;
            mem_array[1] <= 32'b0;
        end else if(WrEn) begin
            case (MemOp)

                //写入字
                3'b000: mem_array[Addr[31:2]] <= DataIn;

                //写入半字
                3'b001: begin
                    case (Addr[1:0])

                        //写入低半字
                        2'b00: mem_array[Addr[31:2]][15:0] <= DataIn[15:0];

                        //写入高半字
                        2'b10: mem_array[Addr[31:2]][31:16] <= DataIn[15:0];

                        //无效地址，不写入
                        default: ;
                    endcase
                end

                //写入字
                3'b010: mem_array[Addr[31:2]] <= DataIn;

                //写入字节
                3'b100: begin
                    case (Addr[1:0])

                        //写入低字节
                        2'b00: mem_array[Addr[31:2]][7:0] <= DataIn[7:0];

                        //写入第二字节
                        2'b01: mem_array[Addr[31:2]][15:8] <= DataIn[7:0]; 

                        //写入第三字节
                        2'b10: mem_array[Addr[31:2]][23:16] <= DataIn[7:0];

                        //写入高字节
                        2'b11: mem_array[Addr[31:2]][31:24] <= DataIn[7:0]; 

                        //无效地址，不写入
                        default: ;
                    endcase
                end

                //写入半字
                3'b101: begin
                    case (Addr[1:0])

                        //写入低半字
                        2'b00: mem_array[Addr[31:2]][15:0] <= DataIn[15:0];

                        //写入高半字
                        2'b10: mem_array[Addr[31:2]][31:16] <= DataIn[15:0];

                        //无效地址，不写入
                        default: ;
                    endcase
                end
                //默认情况下不写入
                default: ;
            endcase
        end
    end

endmodule