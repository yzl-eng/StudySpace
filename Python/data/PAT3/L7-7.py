string=input().strip()
stack=[]
num=0
flag=0
for i in string:
    if i=='(' or i=='[' or i=='{':
        stack.append(i)
    elif i==')' or i==']' or i=='}':
        if len(stack)==0:
            flag=1
            break
        elif i==')' and stack[-1]=='(':
            stack=stack[:-1]
            num+=1
        elif i==']' and stack[-1]=='[':
            stack = stack[:-1]
            num += 1
        elif i=='}' and stack[-1]=='{':
            stack = stack[:-1]
            num += 1
        else:
            flag=1
            break;
    else:
        pass
if len(stack)!=0:
    flag=1
if flag==1:
    print(0)
else:
    print(num)