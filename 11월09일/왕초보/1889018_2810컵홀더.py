import sys
input = sys.stdin.readline

N = int(input())
seats = input().rstrip()

cupholder = 1 # 맨 끝 좌석에는 기본적으로 하나 있음
cupholder += seats.count('S') # S 뒤에는 하나
cupholder += seats.count('LL') # 커플 석 LL 뒤에 하나

if N < cupholder: # 최대 사람이므로 cupholder 갯수가 더 많을 수 있음
    print(N)
else:
    print(cupholder)