n=int(input())
for i in range(n):
    arr=[]
    num1,*slice1=map(int,input().split())
    num2,*slice2=map(int,input().split())
    slice1=list(slice1)
    slice2=list(slice2)
    # max=num1
    flag=0
    # if num2>max:
    max=num2+num1
    for i in range(max):
        arr.append([])
        for t in range(max):
            arr[i].append(0)
    for i in range(0,len(slice1)-1,2):
        arr[slice1[i]][slice1[i+1]]=1
    for i in range(0, len(slice2)-1,2):
        arr[slice2[i]][slice2[i + 1]] = 1
    for i in range(max):
        for t in range(max):
            if arr[i][t]==0:
                flag=1
                break
        if flag==1:
            break
    if flag==1:
        print("NO")
    else:
        print("YES")