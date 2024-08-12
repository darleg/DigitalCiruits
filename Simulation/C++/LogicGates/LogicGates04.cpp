// LogicGates04.cpp

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

class NXOR : public BGate {
private:
    bool inA = false;
    bool inB = false;

public:
    NXOR(string n) : BGate(n) {}

    bool Logic()
    {
        bool inA = getA();
        bool inB = getB();
        bool Xor = (!inA && inB) || (inA && !inB);
        return !Xor;
    }
};

int main()
{
    NOT not01("NOT01");
    cout << not01.gateID("") << " Logic Table\n\n";
    cout << "\tA Z\n";
    not01.putPin(false);
    cout << "\t" << not01.getA() << " " << not01.gateOut() << "\n";
    not01.putPin(true);
    cout << "\t" << not01.getA() << " " << not01.gateOut() << "\n\n";


    NAND nand01("NAND01");
    cout << nand01.gateID("") << " Logic Table\n\n";
    cout << "\tA B Z\n";
    nand01.putPins(false, false);
    cout << "\t" << nand01.getA() << " " << nand01.getB() << " " << nand01.gateOut() << "\n";
    nand01.putPins(false, true);
    cout << "\t" << nand01.getA() << " " << nand01.getB() << " " << nand01.gateOut() << "\n";
    nand01.putPins(true, false);
    cout << "\t" << nand01.getA() << " " << nand01.getB() << " " << nand01.gateOut() << "\n";
    nand01.putPins(true, true);
    std::cout << "\t" << nand01.getA() << " " << nand01.getB() << " " << nand01.gateOut() << "\n\n";

    NOR nor01("NOR01");
    cout << nor01.gateID("") << "  Logic Table\n\n";
    cout << "\tA B Z\n";
    nor01.putPins(false, false);
    cout << "\t" << nor01.getA() << " " << nor01.getB() << " " << nor01.gateOut() << "\n";
    nor01.putPins(false, true);
    cout << "\t" << nor01.getA() << " " << nor01.getB() << " " << nor01.gateOut() << "\n";
    nor01.putPins(true, false);
    cout << "\t" << nor01.getA() << " " << nor01.getB() << " " << nor01.gateOut() << "\n";
    nor01.putPins(true, true);
    cout << "\t" << nor01.getA() << " " << nor01.getB() << " " << nor01.gateOut() << "\n\n";

    NXOR nxor01("NXOR01");
    cout << nxor01.gateID("") << "  Logic Table\n\n";
    cout << "\tA B Z\n";
    nxor01.putPins(false, false);
    cout << "\t" << nxor01.getA() << " " << nxor01.getB() << " " << nxor01.gateOut() << "\n";
    nxor01.putPins(false, true);
    cout << "\t" << nxor01.getA() << " " << nxor01.getB() << " " << nxor01.gateOut() << "\n";
    nxor01.putPins(true, false);
    cout << "\t" << nxor01.getA() << " " << nxor01.getB() << " " << nxor01.gateOut() << "\n";
    nxor01.putPins(true, true);
    cout << "\t" << nxor01.getA() << " " << nxor01.getB() << " " << nxor01.gateOut() << "\n";
}