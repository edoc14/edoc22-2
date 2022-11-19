#include <string>
#include <vector>

using namespace std;

int dp[501][501]; //전역변수니까 0으로 초기화 됨

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    dp[0][0] = triangle[0][0];
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            answer = max(answer, dp[i][j]);
        }
    }

    return answer;
}