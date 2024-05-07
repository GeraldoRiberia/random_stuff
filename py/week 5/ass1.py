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
    return maxF
            
        
orangecap({'test1':{'Pant':84, 'Kohli':120}, 'test2':{'Pant':59, 'Gill':42}})