n=int(input())
num=input().split()
max=1
sum=0
num.sort()
temp=num[0]
for i in num:
    sum=num.count(i)
    if sum>max:
        max=sum
        temp=i
print(temp)
print(max,end="")
