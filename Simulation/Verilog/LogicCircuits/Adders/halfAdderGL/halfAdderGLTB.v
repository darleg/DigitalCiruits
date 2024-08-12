// Testbench for Gate Level Half Adder
module halfAdderGLTB;

reg A;
reg B;
wire S;
wire C;

halfAdderGL hAGL (.a(A),.b(B),.s(S),.c(C));

initial begin
 A = 0; B = 0;
#10; A = 1; B = 0;
#10; A = 0; B = 1;
#10; A = 1; B = 1;
end
initial begin
$monitor ("T=%0t,A=%b,B=%b,S=%b,C=%b",$time,A,B,S,C);
end
endmodule