def sumsquare(l):
    resodd = 0
    reseven = 0
    res =[]
    for i in l:
        if i%2 == 0:
            reseven += i*i
        elif i%2 != 0:
            resodd += i*i
    res.append(resodd)
    res.append(reseven)
    return res
result = sumsquare([1,3,5])
print(result)