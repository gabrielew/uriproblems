dirZero = True
while(dirZero == True):
    linha = input().split()
    L = int(linha[0])
    R = int(linha[1])
    if((L == 0) and (R == 0)):
        dirZero = False
        break;
        
    print(L+R)
