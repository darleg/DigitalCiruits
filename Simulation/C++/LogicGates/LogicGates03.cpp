// LogicGates03.cpp

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
    bool inA;
    bool inB;

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

int main()
{
    NOT not01("NOT01");
    cout  << not01.gateID("") <<" Logic Table\n\n";
    cout << "\tA Z\n";
    not01.putPin(false);
    cout << "\t" << not01.getA() << " " << not01.gateOut() << "\n";
    not01.putPin(true);
    cout << "\t" << not01.getA() << " " << not01.gateOut() << "\n\n";


    AND and01("AND01");
    cout << and01.gateID("") << " Logic Table\n\n";
    cout << "\tA B Z\n";
    and01.putPins(false, false);
    cout << "\t" << and01.getA() << " " << and01.getB() << " " << and01.gateOut() << "\n";
    and01.putPins(false, true);
    cout << "\t" << and01.getA() << " " << and01.getB() << " " << and01.gateOut() << "\n";
    and01.putPins(true, false);
    cout << "\t" << and01.getA() << " " << and01.getB() << " " << and01.gateOut() << "\n";
    and01.putPins(true, true);
    std::cout << "\t" << and01.getA() << " " << and01.getB() << " " << and01.gateOut() << "\n\n";

    OR or01("OR01");
    cout << or01.gateID("") << "  Logic Table\n\n";
    cout << "\tA B Z\n";
    or01.putPins(false, false);
    cout << "\t" << or01.getA() << " " << or01.getB() << " " << or01.gateOut() << "\n";
    or01.putPins(false, true);
    cout << "\t" << or01.getA() << " " << or01.getB() << " " << or01.gateOut() << "\n";
    or01.putPins(true, false);
    cout << "\t" << or01.getA() << " " << or01.getB() << " " << or01.gateOut()  << "\n";
    or01.putPins(true, true);
    cout << "\t" << or01.getA() << " " << or01.getB() << " " << or01.gateOut() << "\n\n";

    XOR xor01("XOR01");
    cout << xor01.gateID("") << "  Logic Table\n\n";
    cout << "\tA B Z\n";
    xor01.putPins(false, false);
    cout << "\t" << xor01.getA() << " " << xor01.getB() << " " << xor01.gateOut() << "\n";
    xor01.putPins(false, true);
    cout << "\t" << xor01.getA() << " " << xor01.getB() << " " << xor01.gateOut() << "\n";
    xor01.putPins(true, false);
    cout << "\t" << xor01.getA() << " " << xor01.getB() << " " << xor01.gateOut() << "\n";
    xor01.putPins(true, true);
    cout << "\t" << xor01.getA() << " " << xor01.getB() << " " << xor01.gateOut() << "\n";
}