tax=0
age,salary=map(float,input().split())
salary=salary/12
if age<50:
    if salary>8000:
        tax=tax+(salary-8000)*0.15+6000*0.1+2000*0.05
    elif salary>=2000:
        tax = tax + (salary - 2000) * 0.1 +  2000 * 0.05
    else:
        tax=salary*0.05
else:
    if salary>8000:
        tax=tax+(salary-8000)*0.10+6000*0.07+2000*0.03
    elif salary>=2000:
        tax = tax + (salary - 2000) * 0.07 +  2000 * 0.03
    else:
        tax=salary*0.03
tax=tax*12
# string=str(tax)
# print(string)
print(f" 一年所应缴纳的税金是:{tax:13.4f}    ",end="")