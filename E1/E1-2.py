class Solution:
  def same_card(self):
    n,m = input().split();
    n = int(n)
    m = int(m)
    A = []
    A0=[]
    for i in input().split():
        A.append(int(i))
    A_max=max(A)
    for k in range(0,A_max+1):
        A0.append(0)
    B = []
    B0 = []
    for i in input().split():
        B.append(int(i))
    B_max=max(B)
    for k in range(0,B_max+1):
        B0.append(0)
    for k in A:
        A0[k] = 1;      
    for k in B:
        B0[k] = 1;
    ifempty=0
    for k in range(1,min(A_max,B_max)+1):
        if A0[k] == 1 and B0[k] == 1:
            ifempty=1
            print(k,end=" ")
    if ifempty == 0:
        print(-1)
solution=Solution()
solution.same_card()