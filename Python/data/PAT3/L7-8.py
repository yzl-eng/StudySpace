n=int(input())
card=map(int,input().split())
card=list(card)
card2=[]
card3=[]
card2=card2+card
card.sort()
# print(card)
# print(card2)
for i in card:
    temp=i-card2.index(i)-1
    if temp<0:
        temp=-temp
    card3.append(temp)
card4=set(card3)
card4=list(card4)
card4.sort(reverse=True)

for t,i in enumerate(card4):
    count=card3.count(i)
    if t!=0:
        print()
    if count>1:
        print(f'{i} {count}',end='')
# print(card3)
# print(card4)