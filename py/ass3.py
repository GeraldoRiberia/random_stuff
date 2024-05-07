posg=0
def hill(l):
    global posg
    hillasc = False
    hilldesc = False
    pos=0
    for i in range(len(l)-1):
        if(l[i+1] > l[i]):
            hillasc = True
        else:
            pos = i
            posg=pos
            break
    if(pos != 0):      
        for i in range(pos,len(l)-1):
            if(l[i+1]< l[i]):
                hilldesc = True
        
    if(hillasc and hilldesc):
        return True
    else:
        return False

def valleydchk(l):
    valleyasc = False
    valleydesc = False
    p = 0
    for i in range(posg,len(l)-1):
        if(l[i+1]<l[i]):
            valleydesc = True
        else:
            p= i
            break
    if(p != 0):       
        for i in range(p,len(l)-1):
            if(l[i+1] > l[i]):
                valleyasc = True

            
    if(valleyasc and valleydesc):
        return True
    else:
        return False
    
def valley(l):
    valleyasc = False
    valleydesc = False
    p = 0
    for i in range(len(l)-1):
        if(l[i+1]<l[i]):
            valleydesc = True
        else:
            p= i
            break
    if(p != 0):       
        for i in range(p,len(l)-1):
            if(l[i+1] > l[i]):
                valleyasc = True

            
    if(valleyasc and valleydesc):
        return True
    else:
        return False
        
def hillvalley(l):
    if(hill(l) and valleydchk(l)):
        return False
    elif(not hill(l) and valley(l)):
        return True
    elif(hill(l) and not valley(l)):
        return True
    else:
        return False

    
ls=[1,2,1]
print(hillvalley(ls))