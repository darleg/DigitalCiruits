// LogicGates01.cpp

#include <iostream>

class NOT
{
private:
    bool nota;

public:
    NOT(bool a = false)
    {
        input(a);
    }

    bool input(bool a)
    {
        nota = !a;
        return Logic();
    }

    bool Logic ()
    {
        return nota;
    }

};

class AND
{
private:
    bool anda, andb;

public:
    AND(bool a = false, bool b = false)
    {
        input(a, b);
    }

    bool input(bool a, bool b)
    {
        anda = a;
        andb = b;
        return Logic();
    }

    bool Logic()
    {
        return anda && andb;
    }

};
class OR
{
private:
    bool ora, orb;

public:
    OR(bool a = false, bool b = false)
    {
        input(a, b);
    }

    bool input(bool a, bool b)
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

class XOR
{
private:
    bool xora, xorb;

public:
    XOR(bool a = false, bool b = false)
    {
        input(a, b);
    }

    bool input(bool a, bool b)
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
    NOT not01;
    std::cout << "   NOT Logic Table\n\n";
    std::cout << "\tA Z\n";
    bool notout1 = not01.input(false);
    std::cout << "\t" << false << " " << notout1 << "\n";
    bool notout2 = not01.input(true);
    std::cout << "\t" << true << " " << notout2 << "\n\n";


    AND and01;
    std::cout << "   AND Logic Table\n\n";
    std::cout << "\tA B Z\n";
    bool andout1 = and01.input(false, false);
    std::cout << "\t" << false << " " << false << " " << andout1 << "\n";
    bool andout2 = and01.input(false, true);
    std::cout << "\t" << false << " " << true << " " << andout2 << "\n";
    bool andout3 = and01.input(true, false);
    std::cout << "\t" << true << " " << false << " " << andout3 << "\n";
    bool andout4 = and01.input(true, true);
    std::cout << "\t" << true << " " << true << " " << andout4 << "\n\n";

    OR or01;
    std::cout << "   OR Logic Table\n\n";
    std::cout << "\tA B Z\n";
    bool orout1 = or01.input(false, false);
    std::cout << "\t" << false << " " << false << " " << orout1 << "\n";
    bool orout2 = or01.input(false, true);
    std::cout << "\t" << false << " " << true << " " << orout2 << "\n";
    bool orout3 = or01.input(true, false);
    std::cout << "\t" << true << " " << false << " " << orout3 << "\n";
    bool orout4 = or01.input(true, true);
    std::cout << "\t" << true << " " << true << " " << orout4 << "\n\n";

    XOR xor01;
    std::cout << "   XOR Logic Table\n\n";
    std::cout << "\tA B Z\n";
    bool xorout1 = xor01.input(false, false);
    std::cout << "\t" << false << " " << false << " " << xorout1 << "\n";
    bool xorout2 = xor01.input(false, true);
    std::cout << "\t" << false << " " << true << " " << xorout2 << "\n";
    bool xorout3 = xor01.input(true, false);
    std::cout << "\t" << true << " " << false << " " << xorout3 << "\n";
    bool xorout4 = xor01.input(true, true);
    std::cout << "\t" << true << " " << true << " " << xorout4 << "\n";
}