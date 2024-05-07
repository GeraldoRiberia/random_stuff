def threesquares(m):
    for p in range(m):
        for q in range(m):
            for r in range(m):
                if((p*p)+(q*q)+(r*r) == m):
                    return True
    
    return False


print(threesquares(1000))