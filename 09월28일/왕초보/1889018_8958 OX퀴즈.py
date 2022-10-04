import sys
input = sys.stdin.readline

N = int(input())
for n in range(N):
    test = input().rstrip()
    score = 0 # 총점
    count = 1 # 연속해서 맞은 갯수
    for t in test:
        if t=='O': # 맞은 경우
            score += count
            count+=1
        else:
            count=1
    print(score)