n, s = map(int, input().split())
m = n / s
m = int(m)
box = input().split()
code = []
for i in range(m):
    temp = input().split()
    temp = temp[::-1]
    code = code + temp
num = int(input())
for i in range(num):
    temp = input()
    try:
        t = box.index(temp)
        print(code[t])
    except:
        print("Wrong Number")
