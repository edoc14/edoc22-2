import sys
input = sys.stdin.readline

N = int(input())
HW = list()

for n in range(N):
    d, t = map(int, input().split(' '))
    HW.append([t-d+1, t, d]) # 마지노 시작일, 종료일, 기간

HW.sort(key = lambda x:x[1], reverse=True) # 종료일 기준으로 내림차순 정렬

for n in range(N-1):
    if HW[n][0]<= HW[n+1][1] <= HW[n+1][1]: # 만약 과제 기간이 겹치면
        temp = HW[n+1][1]-HW[n][0]+1 # 겹친만큼 먼저 해야 하는 과제 기간을 땡김
        HW[n+1][1] -= temp
        HW[n+1][0] -= temp

print(HW[-1][0]-1) # 가장 먼저 해야 하는 과제의 시작일-1까지 놀 수 있음