distant=float(input())
speed_j,speed_m,speed_t=map(float,input().split())
time=distant/(speed_j+speed_m)
sum=speed_t*time
print(f'{sum:.2f}')