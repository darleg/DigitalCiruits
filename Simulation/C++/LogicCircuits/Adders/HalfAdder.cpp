// HalfAdder.cpp

#include <iostream>
#include <string.h>
using namespace std;

class Gate
{
private:
    string ID;
    bool out;
public:
    Gate(string n) {
        ID = n;
    }
    string gateID(string n) {
        return ID;
    }
    bool gateOut() {
        out = Logic();
        return out;
    }

    virtual bool Logic() {
        cout << "ERROR! Logic BASE" << endl;
        return false;
    }
};
class UGate : public Gate {
private:
    bool A;
public:
    UGate(string n) : Gate(n) {
        A = false;
    }

    void putPin(bool a)
    {
        A = a;
    }
    bool getA() { return A; }


};
class BGate : public Gate {
private:
    bool inA;
    bool inB;
public:
    BGate(string n) : Gate(n) {
        inA = false;
        inB = false;
    }
    void putPins(bool a, bool b)
    {
        inA = a;
        inB = b;
    }
    bool getA() { return inA; }
    bool getB() { return inB; }
};

class NOT : public UGate {

public:
    NOT(string n) : UGate(n) {}

    virtual bool Logic()
    {
        bool a = getA();
        return !a;

    }

};

class AND : public BGate {

public:
    AND(string n) : BGate(n) {}

    virtual bool Logic()
    {
        bool apin = getA();
        bool bpin = getB();
        return  apin && bpin;
    }

};
class OR : public BGate {
private:
    bool inA = false;
    bool inB = false;
public:
    OR(string n) : BGate(n) {}

    virtual bool Logic()
    {
        bool inA = getA();
        bool inB = getB();
        return inA || inB;
    }

};

class XOR : public BGate {
private:
    bool inA = false;
    bool inB = false;

public:
    XOR(string n) : BGate(n) {}

    bool Logic()
    {
        bool inA = getA();
        bool inB = getB();
        return (!inA && inB) || (inA && !inB);
    }
};

class NAND : public BGate {

public:
    NAND(string n) : BGate(n) {}

    virtual bool Logic()
    {
        bool apin = getA();
        bool bpin = getB();
        bool And = apin && bpin;
        return !And;
    }
};

class NOR : public BGate {
private:
    bool inA = false;
    bool inB = false;

public:
    NOR(string n) : BGate(n) {}

    virtual bool Logic()
    {
        bool inA = getA();
        bool inB = getB();
        bool Or = inA || inB;
        return !Or;
    }

};

void halfadder(bool a, bool b) {
    bool inA = a;
    bool inB = b;
    XOR xor01("xorID01");
    AND and01("andID01");
    xor01.putPins(inA, inB);
    and01.putPins(inA, inB);
    bool sum = xor01.gateOut();
    bool carry = and01.gateOut();
    cout << " A B Sum Carry\n";
    cout << " " << inA << " " << inB << "  " << sum << "    " << carry << endl;

};

int main() {
    halfadder(false, false);
    halfadder(false, true);
    halfadder(true, false);
    halfadder(true, true);
}