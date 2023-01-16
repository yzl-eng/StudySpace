n=int(input())
arr=input().split()
num=input()
try:
    t=arr.index(num)
    print(t)
except:
    print("Not Exist!")