module GatedSRLatchGLTB;
reg S,R, E;
wire Q;
wire notQ;


GatedSRLatchGL dut(.s(S), .r(R), .e(E),.q(Q), .notq(notQ));

initial begin
$monitor("simtime = %g, E = %b, S = %b, R = %b, Q = %b, notQ = %b", $time, E, S, R, Q, notQ);
end

initial begin 
#10 E = 0; S =0; R=0;
#10 E = 0; S =0; R=1;
#10 E = 0; S =1; R=0;
#10 E = 0; S =1; R=1;
#10 E = 1; S =0; R=0;
#10 E = 1; S =0; R=1;
#10 E = 1; S =1; R=0;
#10 E = 1; S =1; R=1;
end 
endmodule