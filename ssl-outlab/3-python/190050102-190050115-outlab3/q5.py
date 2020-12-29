def rotate(m):
    a = 0
    b = 0
    ans = []
    
    for i in m:
        temp = []
        for j in i:
            temp.append(i)
        ans.append(temp)
    
    for i in m:
        b = 0
        for j in i:
            ans[a][len(m[a])-b-1] = m[b][a]
            b+=1
        a+=1
    
    return ans