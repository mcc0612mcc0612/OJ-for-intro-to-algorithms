class Solution:
  def missing_number(self):
    n = int(input());
    record = []
    for i in input().split():
      record.append(int(i))
    array1 =[]
    for k in range(0,n+1):
      array1.append(1)
    for k in record:
      array1[k] = 0
    for k in range(1,n+1):
      if array1[k] == 1:
        print(k)
solution=Solution()
solution.missing_number()