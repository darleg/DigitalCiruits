module SRLatchDF(nots, notr, q, notq);

input nots, notr;
output q, notq;

assign q = ~(nots & notq);
assign notq = ~(notr & q);

endmodule