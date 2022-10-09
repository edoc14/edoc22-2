import sys

input = sys.stdin.readline

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        dp = [0 for _ in range(200)]
        for _ in range(n):
            s, d = map(int, input().split())
            # 서로 마주보는 방들이 같은 복도를 사용하고 있음을 나타내기 위해 시작 방과 도착 방을 각각 1씩 빼주고 2로 나눠준다
            s = (s - 1) // 2
            d = (d - 1) // 2
            if s > d:  # 만약 시작점이 도착점보다 큰 경우, 시작점과 도착점을 서로 바꿔준다
                temp = d
                d = s
                s = temp
            for i in range(s, d + 1):  # 테이블 옮길 때 사용하는 복도에 10씩 더해준다
                dp[i] += 10
        print(max(dp))  # dp 중에서 이동 시간이 가장 큰 값을 출력한다
