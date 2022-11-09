import sys
input = sys.stdin.readline

A, B, C = map(int, input().split(' '))

if B>=C: # 생산 비용이 판매비용보다 크면 아무리 생산해도 손익분기점 못 넘음
    print(-1)
else:
    print(A//(C-B)+1) # 손익분기점