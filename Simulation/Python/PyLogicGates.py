def NOT(A):
	return ~A+2
def AND(A, B):
	return A & B
def OR(A, B):
	return A | B
def NAND(A, B):
	return NOT(AND(A, B))
def NOR(A, B):
	return NOT(OR(A, B))
def XOR(A, B):
	return A ^ B
def XNOR(A, B):
	return NOT(XOR(A, B))

print("NOT Truth Table")
print("   A  Y")
print("   1 ", NOT(0))
print("   0 ", NOT(1))

print("AND Truth Table")
print("   A  B  Y")
print("   0  0 ", AND(0, 0))
print("   0  1 ", AND(0, 1))
print("   1  0 ", AND(1, 0))
print("   1  1 ", AND(1, 1))

print("OR Truth Table")
print("   A  B  Y")
print("   0  0 ", OR(0, 0))
print("   0  1 ", OR(0, 1))
print("   1  0 ", OR(1, 0))
print("   1  1 ", OR(1, 1))

print("NAND Truth Table")
print("   A  B  Y")
print("   0  0 ", NAND(0, 0))
print("   0  1 ", NAND(0, 1))
print("   1  0 ", NAND(1, 0))
print("   1  1 ", NAND(1, 1))	

print("NOR Truth Table")
print("   A  B  Y")
print("   0  0 ", NOR(0, 0))
print("   0  1 ", NOR(0, 1))
print("   1  0 ", NOR(1, 0))
print("   1  1 ", NOR(1, 1))

print("XOR Truth Table")
print("   A  B  Y")
print("   0  0 ", XOR(0, 0))
print("   0  1 ", XOR(0, 1))
print("   1  0 ", XOR(1, 0))
print("   1  1 ", XOR(1, 1))

print("XNOR Truth Table")
print("   A  B  Y")
print("   0  0 ", XNOR(0, 0))
print("   0  1 ", XNOR(0, 1))
print("   1  0 ", XNOR(1, 0))
print("   1  1 ", XNOR(1, 1))
