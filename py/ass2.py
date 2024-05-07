def repfree(s):
    wrep = []
    for i in s:
        if i in wrep :
            return False
        else:
            wrep.append(i)
    print(wrep)
    return True

print(repfree("abracadabra"))