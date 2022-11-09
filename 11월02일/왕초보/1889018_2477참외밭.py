import sys
input = sys.stdin.readline 

K = int(input())

width = list()
height = list()
dist = list()
for _ in range(6):
    direct, distance = map(int, input().split(' '))
    dist.append(distance)
    if direct > 2:
        width.append(distance)
    else:
        height.append(distance)

w_max = max(width)
h_max = max(height)
ans = w_max * h_max

w_in = dist.index(w_max) # 제일 긴 가로 변의 인덱스
h_in = dist.index(h_max) # 제일 긴 세로 변의 인덱스
w_sub = abs(dist[(h_in-1)%6]-dist[(h_in+1)%6]) # 제일 긴 세로 변의 양 옆의 가로 변
h_sub = abs(dist[(w_in-1)%6]-dist[(w_in+1)%6]) # 제일 긴 가로 변의 양 옆의 세로 변

ans -= w_sub*h_sub # 빼야 하는 작은 사각형

print(ans*K)