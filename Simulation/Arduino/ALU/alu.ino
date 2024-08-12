// C++ code
//
int rega0 = 1;
int rega1 = 2;
int rega2 = 3;
int rega3 = 4;
  
int regb0 = 5;
int regb1 = 6;
int regb2 = 7;
int regb3 = 8;
  
int regc0 = 9;
int regc1 = 10;
int regc2 = 11;
int regc3 = 12;
int regc4 = 13;
  
int mux0 = 14;
int mux1 = 15;
int mux2 = 16;
int mux3 = 17;

int regA = 0;
int regB = 0;
int regC = 0;
int OPmux = 0;

const int Add = 0;
const int Sub = 1;
const int Mul = 2;
const int Div = 3;
const int Not = 4;
const int And = 5;
const int Or  = 6;
const int Nand = 7;
const int Nor = 8;
const int Xor = 9;
const int Sftl = 10;
const int Sftr = 11;

void setup()
{
 
  
  pinMode(rega0, INPUT);
  pinMode(rega1, INPUT);
  pinMode(rega2, INPUT);
  pinMode(rega3, INPUT);
  
  pinMode(regb0, INPUT);
  pinMode(regb1, INPUT);
  pinMode(regb2, INPUT);
  pinMode(regb3, INPUT);
  
  pinMode(regc0, OUTPUT);
  pinMode(regc1, OUTPUT);
  pinMode(regc2, OUTPUT);
  pinMode(regc3, OUTPUT);
  pinMode(regc4, OUTPUT);
  
  pinMode(mux0, INPUT);
  pinMode(mux1, INPUT);
  pinMode(mux2, INPUT);
  pinMode(mux3, INPUT);
  
  
}

void loop()
{
  regA = digitalRead(rega0);
  regA = regA + (digitalRead(rega1)*2);
  regA = regA + (digitalRead(rega2)*4);
  regA = regA + (digitalRead(rega3)*8);
  
  regB = digitalRead(regb0);
  regB = regB + (digitalRead(regb1)*2);
  regB = regB + (digitalRead(regb2)*4);
  regB = regB + (digitalRead(regb3)*8);
  
  OPmux = digitalRead(mux0);
  OPmux = OPmux + (digitalRead(mux1)*2);
  OPmux = OPmux + (digitalRead(mux2)*4);
  OPmux = OPmux + (digitalRead(mux3)*8);
  
  
  switch(OPmux)
  {
    case Add:
    regC = regA + regB;
    break;
    case Sub:
    regC = regA - regB;
    break;
    case Mul:
    regC = regA * regB;
    break;
    case Div:
    regC = regA / regB;
    break;
    case Not:
    regC = ~regA;
    break;
    case And:
    regC = regA & regB;
    break;
    case Or:
    regC = regA | regB;
    break;
    case Nand:
    regC = ~(regA & regB);
    break;
    case Nor:
    regC = ~(regA | regB);
    break;
    case Xor:
    regC = regA ^ regB;
    break;
    case Sftl:
    regC = regA << regB;
    break;
    case Sftr:
    regC = regA >> regB;
    break;
  }
  
  digitalWrite(regc4, regC & 16);
  digitalWrite(regc3, regC & 8);
  digitalWrite(regc2, regC & 4);
  digitalWrite(regc1, regC & 2);
  digitalWrite(regc0, regC & 1);
      
  
}