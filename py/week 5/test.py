
def lcw(w1,w2):
    m = len(w1)
    n = len(w2)
    maxlen = 0  
    maxpos = (m,n)  
    lcw = [ [0 for j in range(n+1)] for i in range(m+1) ]

    for i in range(m-1,-1,-1):
        for j in range(n-1,-1,-1):
            if w1[i] == w2[j]:
                lcw[i][j] = 1 + lcw[i+1][j+1]

                if lcw[i][j] > maxlen:
                    maxlen = lcw[i][j]
                    maxpos = (i,j)

                if lcw[i][j] == maxlen:
                    if w1[maxpos[0]:maxpos[0]+maxlen] > w1[i:i+maxlen]:
                        maxpos = (i,j)
            else:
                lcw[i][j] = 0

    return(maxlen,w1[maxpos[0]:maxpos[0]+maxlen])
            
num = input() 

word = input().strip()
rword = ''.join(reversed(word)) 
(palinlen,palinpat) = lcw(word,rword)
print(palinlen)
print(palinpat)