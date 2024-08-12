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
    return s2, cout


(S,C) = HA(0, 1)
print("Sum ", S)
print("Carry ", C)

(Sum, Cout ) = FA(1, 1, 0)
print("Sum ", Sum)
print("Carry ", Cout)
