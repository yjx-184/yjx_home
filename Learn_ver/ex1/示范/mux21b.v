`timescale 1ns/1ps

module my_and(a,b,c);
    input a,b;
    output c;

    assign c = a & b;
endmodule

module my_or(a,b,c);
    input a,b;
    output c;

    assign c = a | b;
endmodule

module my_not(a,b);
    input a;
    output b;

    assign b = ~a;
endmodule

module mux21b(a,b,s,y);
input a,b,s;
output y;

wire l,r,s_n;
my_not i1(.a(s), .b(s_n));        // 实例化非门，实现~s
  my_and i2(.a(s_n), .b(a), .c(l)); // 实例化与门，实现(~s&a)
  my_and i3(.a(s),   .b(b), .c(r)); // 实例化与门，实现(s&b)
  my_or  i4(.a(l),   .b(r), .c(y)); // 实例化或门，实现(~s&a)|(s&b)
endmodule
