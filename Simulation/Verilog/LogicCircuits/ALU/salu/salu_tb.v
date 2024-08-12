module salu_tb;

    // Inputs
    reg [7:0] opA;
    reg [7:0] opB;
    reg [3:0] Mux;

    // Outputs
    wire [7:0] Result;

    // testing salu
    salu SALU ( .operanda(opA), .operandb(opB), .mux(Mux), .result(Result));

    initial begin
      $dumpfile("wave.vcd");
      $dumpvars(); 
      $monitor("simtime=%g,opA=%b,opB=%b,Mux=%h,Result=%b",$time,opA,opB,Mux,Result);
      // Apply inputs.
        opA = 8'b01101010;
        opB = 8'b00111011;
        // Multiplex
        Mux = 'h0; #10;
        Mux = 'h1; #10;
        Mux = 'h2; #10;
        Mux = 'h3; #10;
        Mux = 'h4; #10;
        Mux = 'h5; #10;
        Mux = 'h6; #10;
        Mux = 'h7; #10;
        Mux = 'h8; #10;
        Mux = 'h9; #10;
        Mux = 'hA; #10;
        Mux = 'hB; #10;
    end
      
endmodule