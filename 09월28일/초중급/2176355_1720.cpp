#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    int dp[31];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
    }

    int t = dp[n / 2]; //짝수번째
    if (n % 2 == 0) {
        t += 2 * dp[n / 2 - 1]; //홀수번째
    }

    cout << (dp[n] - t) / 2 + t;

    return 0;
}