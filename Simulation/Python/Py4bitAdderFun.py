import array as reg

def AND(A, B):
    return A & B
def OR(A, B):
    return A | B
def XOR(A, B):
    return A ^ B

def HA(A, B):
    s = XOR(A, B)
    c = AND(A, B)
    return s, c

def FA(A, B, cin):
    (s1, c1) = HA(A, B)
    (s2, c2) = HA(s1, cin)
    cout = OR(c1, c2)
    return (s2, cout)

def HexAdder():
    (Sreg[3], Cout3) = FA(Areg[3], Breg[3], Cin)
    Cin2 = Cout3
    (Sreg[2], Cout2) = FA(Areg[2], Breg[2], Cin2)
    Cin1 = Cout2
    (Sreg[1], Cout1) = FA(Areg[1], Breg[1], Cin1)
    Cin0 = Cout1
    (Sreg[0], Cout) = FA(Areg[0], Breg[0], Cin0)
    return Cout
    
Areg = reg.array('b', [1,0,1,0])
Breg = reg.array('b', [0,0,1,1])
Sreg = reg.array('b', [0,0,0,0])
Cin = 0

C = HexAdder()
print("A Reg = ", *Areg)
print("B Reg = ", *Breg)
print("Sum =   ", *Sreg)
print("Carry Out = ", C)
