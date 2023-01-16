import math


def judge(num:float)->bool:
    if num<2:
        return False
    if num<=3:
        return True
    if num%2==0:
        return False
    for i in range(3,int(math.sqrt(num))+1,2):
    # for i in range(3,num,2):
        if num%i==0:
            return False
    return True


n,m=map(float,input().split())
arr=[]
if n>m:
    n,m=m,n
# print(n,m)
if n<2 and m>2:
    n=2
max=-1
for i in range(int(m),int(n-1),-1):
    if judge(i):
        max=i
        break
if max==-1:
    print("None",end="")
else:
    print(max,end="")

