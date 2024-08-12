//Simple ALU
//`timescale 1ns/100ps
module salu(operanda,operandb,mux,result);
    
    //inputs,outputs and wires
    input [7:0] operanda,operandb;
    input [3:0] mux;
    output [7:0] result;
    wire [7:0] op1,op2;
    reg [7:0] r;

    parameter [3:0] Add = 4'h0,
                    Sub = 4'h1,
                    Mul = 4'h2,
                    Div = 4'h3,
                    Not = 4'h4,
                    And = 4'h5,
                    Or  = 4'h6,
                    Nand= 4'h7,
                    Nor = 4'h8,
                    Xor = 4'h9,
                    Shtl= 4'ha,
                    Shtr= 4'hb;

    //variables for operations
    assign op1 = operanda;
    assign op2 = operandb;
    //Assign the output 
    assign result = r;

    always @(mux or op1 or op2)
    begin
        case (mux)
         Add : r = op1 + op2;    //Add
         Sub : r = op1 - op2;    //Sub
         Mul : r = op1 * op2;    //Mul
         Div : r = op1 / op2;    //Div
         Not : r = ~op1;         //NOT
         And : r = op1 & op2;    //AND
         Or  : r = op1 | op2;    //OR
         Nand: r = ~(op1 & op2); //NAND 
         Nor : r = ~(op1 | op2); //NOR                
         Xor : r = op1 ^ op2;    //XOR
         Shtl: r = op1 << 1;     //Logical shift left
         Shtr: r = op1 >> 1;     //Logical shift right
        endcase 
    end
    
endmodule