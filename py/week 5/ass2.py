def orangecap(d):
    st = dict()
    keys = set()
    m = ()
    for i in d:
        keys.update(set(d[i].keys()))
    for i in keys:   
        st[i] = 0
    for i in d:
        for j in d[i]:
            if(j in keys):
                st[j] += d[i][j]
    maxVal = max(st.values())
    maxPlayer=(str(list(st.keys())[list(st.values()).index(maxVal)]))
    maxF = (maxPlayer,maxVal)
    print(maxF)
            
        

def addpoly(p1,p2):
    r1 = len(p1)
    r2 = len(p2)
    p3 = list()
    i = 0 
    j =0
    while( i< r1 and j <r2):
        if(p1[i][1] == p2[j][1]):
            r = p1[i][0]+p2[j][0]
            if( r == 0):
                i+=1
                j+=1
                continue
            res = (r,p1[i][1])
            p3.append(res)
            i+=1
            j+=1
        elif( p1[i][1] < p2[j][1]):
            res = (p2[j][0],p2[j][1])
            p3.append(res)
            j+=1
        else:
            res = (p1[i][0],p1[i][1])
            p3.append(res)
            i+=1
    while( i< r1):
        res = (p1[i][0],p1[i][1])
        p3.append(res)
        i+=1
    while( j<r2):
        res = (p2[j][0],p2[j][1])
        p3.append(res)
        j+=1
            
    print(p3)
    
def multpoly(p1,p2):
    r1 = len(p1)
    r2 = len(p2)
    p3 = list()
    i = 0 
    j =0
    for i in range(0,r1):
        for j in range(0,r2):
            res = (p1[i][0]*p2[j][0],p1[i][1]+p2[j][1])
            p3.append(res)
    r3 = len(p3)
    rr = int((r3/2))
    re = list()
    for i in range(0,r3):
        for j in range(i+1,r3):
            if(p3[i][1] == p3[j][1]):
                re1 = p3[i][0]+p3[j][0]
                if(re1 == 0):
                    re.append(p3[i])
                    re.append(p3[j])
    
    for i in re:
        p3.remove(i)
    print(p3)
    

  
orangecap({'match1':{'player1':57, 'player2':38}, 'match2':{'player3':9, 'player1':42}, 'match3':{'player2':41, 'player4':63, 'player3':91}, 'match4':{'player2':31, 'player4':73, 'player3':88}})
addpoly([(5,4),(3,2)],[(-4,1),(-2,0)])  
multpoly([(1,1),(1,0)],[(1,1),(-1,0)])