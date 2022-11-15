import  sys
def solve(cnt, s, num):
    if cnt == len(s):
        dp.append(int(s))
        return
    for i in range(num, -1, -1):
        if not s:
            solve(cnt, s + str(i), num - 1)
        else:
            if int(s[-1]) > i:
                solve(cnt, s + str(i), i - 1)
n = int(sys.stdin.readline())
dp = []
for i in range(10):
    dp.append(i)
for i in range(2, 11):
    solve(i, '', 9)
dp.sort()
if len(dp) - 1 < n:
    print(-1)
else:
    print(dp[n])