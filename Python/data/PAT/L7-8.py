import math


def judge(num: int) -> bool:
    if num < 2:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(num)) + 1, 2):
        # for i in range(3, num, 2):
        if num % i == 0:
            return False
    return True


m, n = map(int, input().split())
sum = 0
arr = []
if m < 2:
    m = 2
for i in range(m, n + 1):
    if judge(i):
        arr.append(i)
for i in range(len(arr)):
    for t in range(i, len(arr)):
        for j in range(t, len(arr)):
            if judge(arr[i] * arr[t] + arr[j]) and judge(arr[i] * arr[j] + arr[t]) and judge(
                    arr[j] * arr[t] + arr[i]) and not (
                    i == t and i == j and t == j):
                sum = sum + 1
                # print(i,t,j)
print(sum)
