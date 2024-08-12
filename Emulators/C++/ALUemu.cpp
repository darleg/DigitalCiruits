#include <iostream>
using namespace std;

int regA = 0;
int regB = 0;
int regC = 0;
int muxOP = 0;

const int Add = 0;
const int Sub = 1;
const int Mul = 2;
const int Div = 3;
const int Not = 4;
const int And = 5;
const int Or = 6;
const int Nand = 7;
const int Nor = 8;
const int Xor = 9;
const int Sftl = 10;
const int Sftr = 11;

struct instruction {
    int muxOP;
    int regA;
    int regB;
};

int main()
{
    cout << " ALU Test\n";
    cout << "op " << "A  " "B  " << "C  " << endl;
    instruction mem[4] = { {Add,2,2},{Sub,4,3},{Div,4,2},{And,5,4} };
    //while (true)
    for (const auto& inst : mem)
    {
        regA = inst.regA;
        regB = inst.regB;
        muxOP = inst.muxOP;
        switch (muxOP)
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

        cout << muxOP << "  " << regA << "  " << regB << "  " << regC << endl;
    }
}