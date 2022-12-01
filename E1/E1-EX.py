n = int(input())
mlist = list(map(int,input().split()))
occurences={}
for i in mlist:
    occurences[i]= mlist.count(i)
a = sorted(occurences.items(),key=lambda x:x[1])
print(a)
for t in a:
    for k in range(t[1]):
        print(t[0],end=" ")
