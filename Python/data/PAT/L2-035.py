class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right

def tree_build(x:int):
    global top
    if x<=n:
        tree_build(x*2)
        tree_build(x*2+1)
        a[x]=lst[top]
        top=top+1


lst=[]
n=int(input())
lst=map(int,input().split())
lst=list(lst)
# lst=lst[::-1]
a=[0 for i in range(n+1)]
top=0
tree_build(1)
for t,i in enumerate(a[1:n+1]):
    if t!=0:
        print(" ",end="")
    print(i,end='')


