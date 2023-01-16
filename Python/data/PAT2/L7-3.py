num=map(int,input().split())
num=list(num)
num.sort()
for t,i in enumerate(num):
    if t>0:
        print("<",end="")
    print(f"{i:c}",end='')
