#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int answer = 0;

    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][1]; //열
        int y = puddles[i][0]; //행
        dp[x][y] = -1;
    }

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)
                continue;
            if (dp[i][j] == -1)
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }

    answer = dp[n][m] % 1000000007;
    return answer;
}