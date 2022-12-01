n = int(input())
mlist = list(map(int,input().split()))
li = [0]*(max(mlist)+1)
power = [0]*(max(mlist)+1)
res = 0
for i in range(n):
    li[mlist[i]] += 1
    if i >=1:
        if mlist[i]>mlist[i-1]:
            power[mlist[i]] = power[mlist[i-1]]-sum(li[mlist[i-1]+1:mlist[i]+1])+1
        elif mlist[i]<mlist[i-1]:
            power[mlist[i]] = power[mlist[i-1]]+sum(li[mlist[i]+1:mlist[i-1]+1]);
        res += power[mlist[i]]
    if res >= 10000007:
       res -= 10000007
print(res)