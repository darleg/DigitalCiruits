// Testbench for Data Flow Full Adder
module fullAdderDFTB;

reg A;
reg B;
reg Cin;
wire Sum;
wire Carry;

fullAdderDF fADF (.a(A),.b(B),.cin(Cin),.sum(Sum),.carry(Carry));

initial begin
 A = 0; B = 0;
#10; A = 1; B = 0; Cin = 0;
#10; A = 0; B = 1; Cin = 0;
#10; A = 1; B = 1; Cin = 1;
end
initial begin
$monitor ("T=%0t,A=%b,B=%b,Cin=%b,Sum=%b,Carry=%b",$time,A,B,Cin,Sum,Carry);
end
endmodule