module SRLatchGLTB;
reg NOTS,NOTR;
wire Q;
wire NOTQ;
SRLatchGL dut(.nots(NOTS), .notr(NOTR), .q(Q), .notq(NOTQ));
initial
begin
#10 NOTS =0; NOTR=0;
#10 NOTS =0; NOTR=1;
#10 NOTS =1; NOTR=0;
#10 NOTS =1; NOTR=1;
end
initial
begin
$monitor("simtime = %g, NOTS =%b, NOTR =%b, Q =%b, NOTQ =%b", $time,NOTS,NOTR,Q,NOTQ);
end
endmodule