def solution(triangle):
    answer = 0
    N = len(triangle)
    dp = [[0 for n in range(N)] for n in range(N)]
    dp[0][0] = triangle[0][0]
    for i in range(1, N):
        dp[i][0] = dp[i-1][0] + triangle[i][0]
        dp[i][i] = dp[i-1][i-1] + triangle[i][i]
    for i in range(2, N):
        for j in range(1, i):
            dp[i][j] = triangle[i][j] + max(dp[i-1][j], dp[i-1][j-1])

    answer = max(dp[N-1])

    return answer