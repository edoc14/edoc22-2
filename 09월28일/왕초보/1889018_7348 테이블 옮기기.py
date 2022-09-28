import sys
input = sys.stdin.readline

T = int(input())

for t in range(T):
    N = int(input())
    room = dict() # 방 복도의 점유 여부
    for n in range(N):
        s, t = map(int, input().split(' '))
        if s>t:
            temp = s
            s = t
            t = temp
        if s!=t:
            for i in range(s, t+1): # s, t 사이의 방이 중첩되지 않는지 확인
                if i not in room:
                    room[i]=0
                room[i]+=1
    
    print(10*max(room.values())) # 중첩된 복도의 최대 횟수에 10분을 곱함