n=int(input().strip())
arr=map(int,input().split())
arr=list(arr)
max=0
num=[]
for i in range(len(arr)):
    if i>0:
        num.append(i)

if num:
    for i in num:
        temp=arr.index(i)
        sum=0
        for t in arr[temp:len(arr)+1]:
            sum=sum+t
            if max<sum:
                max=sum
print(max)
