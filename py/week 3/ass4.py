def remdup(l):
    c = []
    for i in l :
        if i not in c:
            c.append(i)
    return c

res = remdup([1,2,1,3,4,3,1])
print(res)