import sys
input = sys.stdin.readline

N = int(input())
money, B = map(int, input().split(' ')) # 도우 가격
pizza = int(input()) # 도우 열량

D = list()
for n in range(N):
    D.append(int(input()))

D.sort(reverse=True) # 가격 높은 토핑부터 올리는게 이득
for d in D:
    if (pizza+d)/(money+B) > (pizza/money): # 올려서 가격 대비 열량이 커지면 확정
        pizza += d
        money += B

print(pizza//money)