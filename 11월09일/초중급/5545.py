import sys
input=sys.stdin.readline

n=int(input())
a,b=map(int,input().split())
c=int(input())
d=[]
for i in range(n):
    d.append(int(input()))
    
d.sort(reverse=True)
price=a ; k=c
temp=k//price
i=0

while(i<n):
    price+=b
    k+=d[i]
    if temp>(k//price):
        print(temp)
        exit()
    temp=k//price
    i+=1
print(temp)

'''
토핑 3가지
도우 12 토핑 2 => 12+6 = 18
도우 열량 200 토핑 열량 50 300 100 => 650

1) 토핑 선택 X 
2) 토핑 1개 선택
3) 토핑 2개 선택
*** 토핑 n개 선택

열량이 가장 큰 거부터 선택해보기!!
'''
