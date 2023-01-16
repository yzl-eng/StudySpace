n = int(input())
string = input().strip()
set1=set(string)
count=0
flag=0
flag_l=0
flag_r=len(string)-1
sum=0
string=list(string)
for i in set1:
    if string.count(i)%2!=0:
        count = count + 1
        if count > 1:
            print("Impossible", end="")
            flag=1
            break
if flag==0:
    while flag_r!=flag_l and flag_l+1!=flag_r:
        for i in range(flag_r,flag_l-1,-1):
            if string[i]==string[flag_l]:
                for t in range(i,flag_r):
                    string[t],string[t+1]=string[t+1],string[t]
                    # temp=string[t+1]
                    # string[t+1]=string[t]
                    # string[t]=temp
                    sum += 1
                flag_r-=1
                flag_l+=1
                break
    print(sum)




# string2=string[slice+1:]
# num=set(string2)-set(string)
# if len(num)>1:
#     print("Impossible",end="")