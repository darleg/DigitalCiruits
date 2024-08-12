// LogicGates02.cpp

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
    string gateID() {
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
class UGate : Gate {
private:
    bool a;
public:
    UGate(string n) : Gate(n){
        a = false;
    }
    
    virtual void input()
    {
        cout << "ERROR! input BASE" << endl;
    }
    
   
};
class BGate : Gate {
private:
    bool a, b;
public:
    BGate(string n) : Gate(n){
        a = false;
        b = false;
    }
    virtual void input()
    {
        cout << "ERROR!" << endl;
    }
};

class NOT : UGate {
private:
    bool nota;

public:
    NOT(string n) : UGate(n){}

    virtual bool input(bool a)
    {
        return a;
    }

    virtual bool Logic(bool a)
    {
        bool nota = !a;
        return nota;
    }

};

class AND : BGate {
private:
    bool anda, andb;

public:
    AND(string n) : BGate(n) {}

    virtual bool input(bool a, bool b)
    {
        anda = a;
        andb = b;
        return Logic();
    }

    virtual bool Logic()
    {
        return anda && andb;
    }

};
class OR : BGate {
private:
    bool ora, orb;

public:
    OR(string n) : BGate(n) {}

    virtual bool input(bool a, bool b)
    {
        ora = a;
        orb = b;
        return Logic();
    }

    bool Logic()
    {
        return ora || orb;
    }

};

class XOR : BGate {
private:
    bool xora, xorb;

public:
    XOR(string n) : BGate(n) {}

    virtual bool input(bool a, bool b)
    {
        xora = a;
        xorb = b;
        return Logic();
    }

    bool Logic()
    {
        return (!xora && xorb) || (xora && !xorb);
    }

};

int main()
{
    NOT not01("NOT01");
    cout << "   NOT Logic Table\n\n";
    cout << "\tA Z\n";
    bool notout1 = not01.input(false);
    cout << "\t" << false << " " << notout1 << "\n";
    bool notout2 = not01.input(true);
    cout << "\t" << true << " " << notout2 << "\n\n";


    AND and01("AND01");
    cout << "AND Logic Table\n\n";
    cout << "\tA B Z\n";
    bool andout1 = and01.input(false, false);
    cout << "\t" << false << " " << false << " " << andout1 << "\n";
    bool andout2 = and01.input(false, true);
    cout << "\t" << false << " " << true << " " << andout2 << "\n";
    bool andout3 = and01.input(true, false);
    cout << "\t" << true << " " << false << " " << andout3 << "\n";
    bool andout4 = and01.input(true, true);
    std::cout << "\t" << true << " " << true << " " << andout4 << "\n\n";

    OR or01( "OR01");
    cout << "   OR Logic Table\n\n";
    cout << "\tA B Z\n";
    bool orout1 = or01.input(false, false);
    cout << "\t" << false << " " << false << " " << orout1 << "\n";
    bool orout2 = or01.input(false, true);
    cout << "\t" << false << " " << true << " " << orout2 << "\n";
    bool orout3 = or01.input(true, false);
    cout << "\t" << true << " " << false << " " << orout3 << "\n";
    bool orout4 = or01.input(true, true);
    cout << "\t" << true << " " << true << " " << orout4 << "\n\n";

    XOR xor01("XOR01");
    cout << "   XOR Logic Table\n\n";
    cout << "\tA B Z\n";
    bool xorout1 = xor01.input(false, false);
    cout << "\t" << false << " " << false << " " << xorout1 << "\n";
    bool xorout2 = xor01.input(false, true);
    cout << "\t" << false << " " << true << " " << xorout2 << "\n";
    bool xorout3 = xor01.input(true, false);
    cout << "\t" << true << " " << false << " " << xorout3 << "\n";
    bool xorout4 = xor01.input(true, true);
    cout << "\t" << true << " " << true << " " << xorout4 << "\n";
}