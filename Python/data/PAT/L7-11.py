class Member:
    def __init__(self, name: str, k: int, like: set):
        self.name = name
        self.k = k
        self.like = like
        self.length = len(like)


def func(arr: Member):
    return arr.length,1000-arr.k


n = int(input())
arr = []
for i in range(n):
    name, k, *like = input().split()
    like = set(like)
    member = Member(name, int(k), like)
    arr.append(member)
arr.sort(key=func,reverse=True)
# for t,i in enumerate(arr[:3]):
#     if not t==0:
#         print(" ",end='')
#     if not i:
#         print('-',end='')
#         break
#     print(i.name,end='')
#     if t==2:
#         print()
for t in range(3):
    if not t == 0:
        print(" ", end='')
    if t<len(arr):
        print(arr[t].name,end='')
    else:
        print('-', end='')
    if t==2:
        print()
