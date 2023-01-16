import math

n,m=map(float,input().split())
sum=math.pi*n**2-math.pi*m**2
print(f"{sum:.2f}")