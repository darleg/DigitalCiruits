module GatedSRLatchGL(s, r, e, q, notq);

input s, r, e;      // Set, Reset and Enable inputs
output q, notq;       // Q and  not Q outputs
wire nots;
wire notr;

// Logic for Gated SR Latch
and(nots, e, s);   // And gate for enable and Set input
and(notr, e, r);   // And gate for enable and ReSet input
// RS Latch part of Gated SR Latch
nor(q, nots, notq);  // nor gate for Q output
nor(notq, notr, q);  // nor gate for notQ output

endmodule