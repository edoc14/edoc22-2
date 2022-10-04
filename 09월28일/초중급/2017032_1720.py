import sys

input = sys.stdin.readline

dp = [0 for _ in range(31)]
dp[1] = 1
dp[2] = 3

if __name__ == '__main__':
    n = int(input())

    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + 2 * dp[i - 2]  # 타일 만드는 모든 경우의 수

    if n < 3:
        print(dp[n])
    else:
        # 좌우대칭인 경우의 수를 중복적으로 더하지 않기 위해, ((모든 경우의 수) + (왼쪽과 오른쪽이 같은 경우의 수))/2를 해준다
        if n % 2 == 0:  # n이 짝수인 경우
            print((dp[n] + 2 * dp[(n - 2) // 2] + dp[n // 2]) // 2)
            # 2*dp[(n - 2) // 2]는 {}2x2{}과 {}(1x2)x2{} 처럼 타일을 놓은 경우
            # dp[n // 2]는 딱 정가운데를 기점으로 앞뒤가 같은 경우
        else:  # n이 홀수인 경우
            print((dp[n] + dp[(n - 1) // 2]) // 2)
            # dp[(n - 1) // 2]는 {}2x1{} 처럼 타일을 놓은 경우
