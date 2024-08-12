module SRLatchGL(nots,notr,q,notq);

input nots, notr;
output q, notq;

nand(q, nots, notq);
nand(notq, notr, q);

endmodule