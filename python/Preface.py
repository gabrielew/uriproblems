import math
linha = input().split()
n1 = int(linha[0])
n2 = int(linha[1])

q = n1/n2
print("q1: ",q)
r = n1%n2
print("r1:",r)

if(q<0):
    print(math.ceil(q),abs(r))
    print("q<")
    if(r<0):
        print(math.ceil(q), abs(r+1))
        print("r<")
else:
    print(math.floor(q),abs(r))
