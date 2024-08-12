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

import array as reg

Areg = reg.array('b', [1,0,1,0])
Breg = reg.array('b', [0,0,1,1])
Sreg = reg.array('b', [0,0,0,0])


Cin =  reg.array('b', [0,0,0,0])
Cout = reg.array('b', [0,0,0,0])

(Sreg[3], Cout[3]) = FA(Areg[3], Breg[3], Cin[3])
Cin[2] = Cout[3]
(Sreg[2], Cout[2]) = FA(Areg[2], Breg[2], Cin[2])
Cin[1] = Cout[2]
(Sreg[1], Cout[1]) = FA(Areg[1], Breg[1], Cin[1])
Cin[0] = Cout[1]
(Sreg[0], Cout[0]) = FA(Areg[0], Breg[0], Cin[0])

print(*Sreg)
