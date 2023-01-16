n,d=map(int,input().split())
weight=map(int,input().split())
price=map(float,input().split())
value=[]
value2=[]
weight=list(weight)
price=list(price)
for i in range(n):
    value.append(price[i]/weight[i])
    value2.append(price[i] / weight[i])
value2.sort(reverse=True)
max=0
sum=0
sum_price=0
i=0
flag=0
while d>sum:
    sum=sum+weight[value.index(value2[i])]
    sum_price=sum_price+price[value.index(value2[i])]
    i = i + 1
    if i==n+1:
        flag=1
        break
if flag==1:
    pass
else:
    i=i-1
    if sum==d:
        pass
    else:
        sum=sum-weight[value.index(value2[i])]
        sum_price = sum_price - price[value.index(value2[i])]
        sum_price=sum_price+(d-sum)*value2[i]
print(f'{sum_price:.2f}')
