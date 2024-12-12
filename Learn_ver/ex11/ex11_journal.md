- [实验十一 RV32I单周期CPU](#实验十一-rv32i单周期cpu)
  - [RV32I指令编码](#rv32i指令编码)
  - [RV32I中的通用寄存器](#rv32i中的通用寄存器)
  - [RV32I中的指令类型](#rv32i中的指令类型)
    - [整数运算指令](#整数运算指令)
    - [控制转移指令](#控制转移指令)
    - [存储器访问指令](#存储器访问指令)
    - [常见伪指令](#常见伪指令)
  - [RV32I电路实现](#rv32i电路实现)
    - [单周期电路设计](#单周期电路设计)
  - [控制通路](#控制通路)
  - [验收实验](#验收实验)
    - [取址](#取址)
      - [Instr\_Mem.v](#instr_memv)
    - [指令存储器](#指令存储器)
      - [Imm\_Gen.v](#imm_genv)
      - [测试结果](#测试结果)
    - [RV32I指令控制信号](#rv32i指令控制信号)
      - [Contr\_Gen.v 测试结果](#contr_genv-测试结果)
    - [寄存器堆 Reg\_File](#寄存器堆-reg_file)
    - [ALU](#alu)
    - [PC加法器输入选择逻辑](#pc加法器输入选择逻辑)
      - [Branch\_COnd.v](#branch_condv)
      - [测试结果](#测试结果-1)
    - [程序计数器PC](#程序计数器pc)
      - [PCMux.v](#pcmuxv)
      - [测试结果](#测试结果-2)
      - [PC.v](#pcv)
    - [数据存储器部分](#数据存储器部分)
      - [Data\_Mem.v](#data_memv)
      - [测试Data\_Mem.v](#测试data_memv)
      - [Data\_Mux.v](#data_muxv)


# 实验十一 RV32I单周期CPU
## RV32I指令编码
![](./pic/RV32I.png)  

**思考：** 为什么会有S-Type/B-Type，U-Type/J-Type这些不同的立即数编码方案？指令相关的立即数为何在编码时采用这样“奇怪”的bit顺序？  

**1.节约指令长度并保持指令对齐**  
RISC-V 是一种固定 32 位指令长度的架构，这种设计的目的是简化硬件解码，并提高指令流水线效率。但这也限制了指令字段的大小。立即数的不同编码顺序设计目的是在有限的指令长度内，同时满足以下需求：  
（ 1 ）**保持字段长度的高效分配：** 立即数需要尽可能的长，以表达更大的范围或更多的偏移量。  
（ 2 ）**与其他字段共存：** 指令中还需要容纳操作码、寄存器地址等字段。  

**2.立即数对齐优化：**  
许多立即数代表字节地址偏移量或程序计数器PC的相对偏移量，它们的最低几位通常是固定为零（对齐限制，比如字对齐）。RISC-V 的立即数编码方式会按照使用需求重新排列，主要是：  

** S-Type 和 B-Type*
* S-Type（存储指令）：立即数被分成两段（imm[11:5] 和 imm[4:0]），分别放在指令的不同位置。这是为了让硬件能够在解码时直接拼接这些字段，生成 12 位偏移量，同时与寄存器地址等字段高效地共享位空间。  
* B-Type（分支指令）：分支目标地址是相对偏移地址，且必须是字对齐的，因此最低两位始终为 0。通过将 imm[11] 移动到高位，imm[12] 作为符号位，硬件可以快速完成符号扩展，并生成目标地址。  
  
** U-Type 和 J-Type*  
* U-Type（长立即数）：提供 20 位的立即数，适用于加载高位立即数（如 LUI 指令）。直接将高位立即数对齐到指令的高位部分。  
* J-Type（跳转指令）：跳转目标地址的编码需要处理字对齐，同时需要表达大范围的偏移量。因此，它使用 {imm[20], imm[10:1], imm[11], imm[19:12]} 的方式排列，这样可以确保符号位（imm[20]）居高位，便于硬件进行符号扩展和跳转目标地址计算。  
  
**总结：**  
这些看似“奇怪”的立即数编码方式是为了在 有限的指令长度中高效表达更多信息，同时优化 硬件解码和执行 的复杂性。通过重新排列立即数位顺序，硬件可以更快地拼接和处理不同类型的立即数，从而减少解码延迟，满足性能需求。  

## RV32I中的通用寄存器
RV32I共32个32bit的通用寄存器x0~x31(寄存器地址为5bit编码），其中寄存器x0中的内容总是0，无法改变。 其他寄存器的别名和寄存器使用约定参见表 Table 12 。需要注意的是，部分寄存器在函数调用时是由调用方（Caller）来负责保存的，部分寄存器是由被调用方（Callee）来保存的。在进行C语言和汇编混合编程时需要注意。  
![](./pic/RV31I_reg.png)  

## RV32I中的指令类型  
本实验中需要实现的RV32I指令含包含以下三类：  
* **整数运算指令 ：** 可以是对两个源寄存器操作数，或一个寄存器一个立即数操作数进行计算后，结果送入目的寄存器。运算操作包括带符号数和无符号数的算术运算、移位、逻辑操作和比较后置位等。  

* **控制转移指令 ：** 条件分支包括beq，bne等等，根据寄存器内容选择是否跳转。无条件跳转指令会将本指令下一条指令地址PC+4存入rd中供函数返回时使用。  

* **存储器访问指令 ：** 对内存操作是首先寄存器加立即数偏移量，以计算结果为地址读取/写入内存。读写时可以是按32位字，16位半字或8位字节来进行读写。读写时区分无符号数和带符号数。注意：RV32I为 Load/Store 型架构，内存中所有数据都需要先load进入寄存器才能进行操作，不能像x86一样直接对内存数据进行算术处理。  
  
### 整数运算指令
![](./pic/zhengshu.png)  
这些整数运算指令所需要完成的操作参见表 Table 13 。说明中R[reg]表示对地址为reg的寄存器进行操作，M[addr]表示对地址为addr的内存进行操作，SEXT(imm)表示对imm进行带符号扩展到32位， <- 表示赋值， << 及 >> 分别表示逻辑左移和右移， >>> 表示算术右移(注意verilog与java中定义的不同)，比较过程中带s和u下标分别表示带符号数和无符号数比较。  
![](./pic/zhiling.png)  

### 控制转移指令
![](./pic/kongzhi.png)  
![](./pic/kongzhi2.png)![](./pic/kongzhi3.png)  

### 存储器访问指令
RV32I提供了按字节、半字和字访问存储器的8条指令。所有访存指令的寻址方式都是寄存器间接寻址方式，访存地址可以不对齐4字节边界，但是在实现中可以要求访存过程中对齐4字节边界。在读取单个字节或半字时，可以按要求对内存数据进行符号扩展或无符号扩展后再存入寄存器。 表 Fig. 76 列出了存储访问类指令的编码方式。 表 Table 15 列出了存储访问类指令的具体操作。  
![](./pic/fangwen.png)  

### 常见伪指令
RISC-V中规定了一些常用的伪指令。这些伪指令一般可以在汇编程序中使用，汇编器会将其转换成对应的指令序列。表 Table 16 介绍了RISC-V的常见伪指令列表。  
![](./pic/weizhiling1.png)  
![](./pic/weizhiling2.png)  

## RV32I电路实现
### 单周期电路设计
在了解了RV32I指令集的指令体系结构（Instruction Set Architecture，ISA)之后，我们将着手设计CPU的微架构（micro architecture）。 同样的一套指令体系结构可以用完全不同的微架构来实现。不同的微架构在实现的时候只要保证程序员可见的状态，即PC、通用寄存器和内存等，在指令执行过程中遵守ISA中的规定即可。具体微架构的实现可以自由发挥。 在本实验中，我们首先来实现单周期CPU的微架构。所谓单周期CPU是指CPU在每一个时钟周期中需要完成一条指令的所有操作，即每个时钟周期完成一条指令。

每条指令的执行过程一般需要以下几个步骤：  
**1.取指令：** 使用本周期新的PC从指令存储器中取出指令，并将其放入指令寄存器IR中。  
**2.指令译码：** 对取出的指令进行分析，生成本周期执行指令所需要的控制信号，并计算下一条指令的地址。  
**3.读取操作数：** 从寄存器堆中读取操作数，并完成立即数的生成。  
**4.运算：** 利用ALU对操作数进行必要的运算。  
**5.寄存器返回：** 将最终结果写回到目的寄存器中。  

每条指令执行过程中的以上几个步骤需要CPU的控制通路和数据通路配合来完成。 其中控制通路主要负责控制信号的生成，通过控制信号来指示数据通路完成具体的数据操作。 数据通路是具体完成数据存取、运算的部件。 控制通路和数据通路分离的开发模式在数字系统中经常可以碰到。其设计的基本指导原则是：控制通路要足够灵活，并能够方便地修改和添加功能，控制通路的性能和时延往往不是优化重点。 反过来，数据通路需要简单且性能强大。数据通路需要以可靠的方案，快速地移动和操作大量数据。 在一个简单且性能强大的数据通路支持下，控制通路可以灵活地通过控制信号的组合来实现各种不同的应用。  

![](./pic/one_CPU.png)  

## 控制通路




## 验收实验
### 取址
#### Instr_Mem.v
```
module Instr_Mem(
    input Rdclk,            //读取时钟
    input [31:0] Rdaddr,    //读取地址
    output [31:0] Instr     //输出指令
);

    //参数定义
    parameter MEM_DEPTH = 256; //指令存储器的深度
    parameter MEM_WIDTH = 32;  //每条指令的宽度

    //指令存储器阵列
    reg [MEM_WIDTH-1:0] mem_array [0:MEM_DEPTH-1];

    //初始化存储器，从外部文件加载指令数据
    initial begin
        $readmemh("instr_mem.hex", mem_array);  //从文件中加载指令
    end

    //在时钟上升沿根据地址读取指令
    always @(posedge Rdclk) begin
        Instr <= mem_array[Rdaddr[31:2]];
    end

endmodule
```

### 指令存储器 
#### Imm_Gen.v
```
module Imm_Gen(
    input [31:0] instr,       // 输入：instr
    input [2:0] ExtOp,        // 扩展操作：用于区分立即数类型
    output reg [31:0] imm     // 输出：生成的32位立即数
);

    always @(*) begin
        case (ExtOp)
            3'b000: // I-Type：立即数操作指令 
                // 最高位为符号位，对其进行扩展。
                imm = {{20{instr[31]}}, instr[31:20]};

            3'b001: // U-Type: 长立即数指令
                imm = {instr[31:12], 12'b0};

            3'b010: // S-Type: 存储器写指令
                imm = {{20{instr[31]}}, instr[31:25], instr[11:7]};

            3'b011: // B-Type: 跳转指令 13位立即数，末尾始终为0
                imm = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};

            3'b100: // J-Type: 长跳转指令
                imm = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
            default: // 默认输出 0
                imm = 32'b0;
        endcase
    end

endmodule


```
#### 测试结果
经过测试，符合拼接规则
```
test 1: imm = 11111111111111111111100000000000
test 2: imm = 11111111111100000000000000000000
test 3: imm = 11111111111111111111111111111111
test 4: imm = 11111111111111111111011111100000
test 5: imm = 11111111111100000000011111100000

```
### RV32I指令控制信号
#### Contr_Gen.v 测试结果
```
yjx@yjx-Lenovo-Legion-R7000-2020:~/Mystudy/yjx_learn/Learn_ver/ex11/CPU/Contr_Gen$ ./Contr_Gen_tb
开始测试
test lui:     ExtOp = 001, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0011
test auipc:   ExtOp = 001, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 1, ALUBsrc = 01, ALUctr = 0000
......
test addi:    ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
test slti:    ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0010
test sltiu:   ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 1010
test xori:    ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0100
test ori:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0110
test andi:    ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0111
test slli:    ExtOp = 001, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0001
test srli:    ExtOp = 001, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0101
test srai:    ExtOp = 001, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 1101
.......
test add:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0000
test sub:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 1000
test sll:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0001
test slt:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0010
test sltu:    ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 1010
test xor:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0100
test srl:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0101
test sra:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 1101
test or:      ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0110
test and:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0111
......
test jal:     ExtOp = 100, RegWr = 1, Branch = 001, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 1, ALUBsrc = 10, ALUctr = 0000
test jalr:    ExtOp = 000, RegWr = 1, Branch = 010, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 1, ALUBsrc = 10, ALUctr = 0000
test beq:     ExtOp = 011, RegWr = 0, Branch = 100, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0010
test bne:     ExtOp = 011, RegWr = 0, Branch = 101, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0010
test blt:     ExtOp = 011, RegWr = 0, Branch = 110, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0010
test bge:     ExtOp = 011, RegWr = 0, Branch = 111, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 0010
test bltu:    ExtOp = 011, RegWr = 0, Branch = 110, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 1010
test bgeu:    ExtOp = 011, RegWr = 0, Branch = 111, MemtoReg = 0, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 00, ALUctr = 1010
......
test bl:      ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 1, MemWr = 0, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
test lh:      ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 1, MemWr = 0, MemOp = 001, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
test lw:      ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 1, MemWr = 0, MemOp = 010, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
test lbu:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 1, MemWr = 0, MemOp = 100, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
test lhu:     ExtOp = 000, RegWr = 1, Branch = 000, MemtoReg = 1, MemWr = 0, MemOp = 101, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
test sb:      ExtOp = 010, RegWr = 0, Branch = 000, MemtoReg = 0, MemWr = 1, MemOp = 000, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
test sh:      ExtOp = 010, RegWr = 0, Branch = 000, MemtoReg = 0, MemWr = 1, MemOp = 001, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
test sw:      ExtOp = 010, RegWr = 0, Branch = 000, MemtoReg = 0, MemWr = 1, MemOp = 010, ALUAsrc = 0, ALUBsrc = 01, ALUctr = 0000
测试结束

```
### 寄存器堆 Reg_File
这个部分直接调用了上一个实验的寄存器堆Reg_FIle.v

### ALU
这个部分稍做加工，也是基本调用了上一个实验的ALU.v

### PC加法器输入选择逻辑
#### Branch_COnd.v
```
module Branch_Cond(
    input [2:0] Branch,
    input Less,
    input Zero,
    output PCAsrc,
    output PCBsrc
);

    always @(*) begin
        //默认情况下, PC + 4
        PCAsrc = 0;  //默认设置为PC + 4
        PCBsrc = 0;  //默认设置为PC + 4
        
        case(Branch)
            3'b000: begin       //非跳转指令
                //PC + 4
                PCAsrc = 0;
                PCBsrc = 0;
            end

            3'b001: begin       //无条件跳转PC目标
                //PC + imm
                PCAsrc = 1;
                PCBsrc = 0;
            end

            3'b010: begin       //无条件跳转寄存器目标
                //rs1 + imm
                PCAsrc = 1;
                PCBsrc = 1;
            end

            3'b100: begin       //条件分支，等于
                case(Zero)
                    1'b0: begin //PC + 4
                        PCAsrc = 0;
                        PCBsrc = 0;
                    end

                    1'b1: begin //PC + imm
                        PCAsrc = 1;
                        PCBsrc = 0;
                    end
                endcase
            end

            3'b101: begin       //条件分支，不等于
                case(Zero)
                    1'b0: begin //PC + imm
                        PCAsrc = 1;
                        PCBsrc = 0;
                    end

                    1'b1: begin //PC + 4
                        PCAsrc = 0;
                        PCBsrc = 0;
                    end
                endcase
            end

            3'b110: begin       //条件分支，小于
                case(Less)
                    1'b0: begin //PC + 4
                        PCAsrc = 0;
                        PCBsrc = 0;
                    end

                    1'b1: begin //PC + imm
                        PCAsrc = 1;
                        PCBsrc = 0;
                    end
                endcase
            end

            3'b111: begin       //条件分支，大于等于
                case(Less)
                    1'b0: begin //PC + imm
                        PCAsrc = 1;
                        PCBsrc = 0;
                    end

                    1'b1: begin //PC + 4
                        PCAsrc = 0;
                        PCBsrc = 0;
                    end

                endcase
            end


        endcase

    end



endmodule
```
#### 测试结果
```
yjx@yjx-Lenovo-Legion-R7000-2020:~/Mystudy/yjx_learn/Learn_ver/ex11/Backup/Branch_Cond$ ./Branch_Cond
Test 1:   Branch: 000, Less = x, Zero = x, PCAsrc = 0, PCBsrc = 0
Test 2:   Branch: 001, Less = x, Zero = x, PCAsrc = 1, PCBsrc = 0
Test 3:   Branch: 010, Less = x, Zero = x, PCAsrc = 1, PCBsrc = 1
Test 4:   Branch: 100, Less = x, Zero = 0, PCAsrc = 0, PCBsrc = 0
Test 5:   Branch: 100, Less = x, Zero = 1, PCAsrc = 1, PCBsrc = 0
Test 6:   Branch: 101, Less = x, Zero = 0, PCAsrc = 1, PCBsrc = 0
Test 7:   Branch: 101, Less = x, Zero = 1, PCAsrc = 0, PCBsrc = 0
Test 8:   Branch: 110, Less = 0, Zero = 1, PCAsrc = 0, PCBsrc = 0
Test 9:   Branch: 110, Less = 1, Zero = 1, PCAsrc = 1, PCBsrc = 0
Test 10:   Branch: 111, Less = 0, Zero = 1, PCAsrc = 1, PCBsrc = 0
Test 11:   Branch: 111, Less = 1, Zero = 1, PCAsrc = 0, PCBsrc = 0

```
### 程序计数器PC
#### PCMux.v
```
module PCMux(
    input [31:0] imm,
    input [31:0] rs1,
    input [31:0] Pc,
    input PCAsrc,
    input PCBsrc,
    output [31:0] NextPC
);

    always @(*) begin
        if(PCAsrc == 0) begin
            //PC + 4
            NextPC = Pc + 4;
        end else begin
            if(PCBsrc == 0) begin
                //PC + imm
                NextPC = Pc + imm;
            end else begin
                //rs1 + imm
                NextPC = rs1 + imm;
            end
        end
    end
endmodule
```
#### 测试结果
```
$ ./PCMux_tb
time                    0, Pc = 00000000, imm = 00000000, rs1 = 00000000, PCAsrc = 0, PCBsrc = 0, NextPC = 00000004
time                10000, Pc = 00000004, imm = 00000008, rs1 = 00000010, PCAsrc = 0, PCBsrc = 0, NextPC = 00000008
time                20000, Pc = 00000004, imm = 00000008, rs1 = 00000010, PCAsrc = 1, PCBsrc = 0, NextPC = 0000000c
time                30000, Pc = 00000004, imm = 00000008, rs1 = 00000010, PCAsrc = 1, PCBsrc = 1, NextPC = 00000018
time                40000, Pc = 00000010, imm = 00000010, rs1 = 00000020, PCAsrc = 0, PCBsrc = 1, NextPC = 00000014
time                50000, Pc = 00000020, imm = 00000004, rs1 = 00000030, PCAsrc = 1, PCBsrc = 1, NextPC = 00000034

```
#### PC.v
```
module PC(
    input [31:0] NextPC,
    input CLK,
    output reg [31:0] Pc
);
    initial begin
        Pc = 32'b0;
    end

    always @(negedge CLK) begin
        Pc <= NextPC;
    end
endmodule
```
### 数据存储器部分
#### Data_Mem.v
```
module Data_Mem(
    input [31:0] Addr,
    input [2:0] MemOp,
    input [31:0] DataIn,
    input WrEn,
    input RdClk,
    input WrClk,
    output [31:0] DataOut
);

    //内存数组（假设内存大小为 256 条指令，每条指令32位宽）
    reg [31:0] mem_array [0:255];

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
                    2'b10: DataOut <= {16'b0, mem_array[Addr[31:2][31:16]]};

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
    always @(negedge WrClk) begin
        if (WrEn) begin
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
```
#### 测试Data_Mem.v
结果显示通过。

#### Data_Mux.v
```
module Data_Mux(
    input [31:0] DataOut_in,
    input [31:0] ALU_Result,
    input MemtoReg,
    output reg [31:0] busW
);

    always @(*) begin
        case(MemtoReg)
            1'b0: busW = ALU_Result;
            1'b1: busW = DataOut_in;
            default: busW = 32'b0;
        endcase
    end

endmodule
```