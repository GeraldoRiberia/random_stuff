
def transpose(x):
    result = [[x[j][i] for j in range(len(x)) ]for i in range(len(x[0]))]
    return result

l= [[1,2,3],[4,5,6]]  
res = transpose(l)

    