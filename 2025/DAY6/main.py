l=[0]
for _ in range(5):
    l.append(' '+input())
r=['']
for i in range(1,len(l)-1):
    r.append(list(map(int,l[i].split())))
r.append(l[len(l)-1].split())
ans=0
for i in range(len(r[len(r)-1])):
    if r[len(r)-1][i]=='*':
        prod=1
        for j in range(1,len(r)-1):
            prod*=r[j][i]
        ans+=prod
    else:
        summ=0
        for j in range(1,len(r)-1):
            summ+=r[j][i]
        ans+=summ
print(ans,end =' ')
active=[]
ans=0
operator=len(r[len(r)-1])-1
for i in range(len(l[1])-1,-1,-1):
    allspace=True
    for j in range(1,len(l)-1):
        if l[j][i]!=' ':
            allspace=False
            break
    if allspace:
        if r[len(r)-1][operator]=='*':
            prod=1
            for j in active:
                prod*=j
            ans+=prod
        else:
            summ=0
            for j in active:
                summ+=j
            ans+=summ
        operator-=1
        active=[]
    cur=0
    for j in range(1,len(l)-1):
            if l[j][i]!=' ':
                cur=10*cur+int(l[j][i])
    if cur:
        active.append(cur)
print(ans)
