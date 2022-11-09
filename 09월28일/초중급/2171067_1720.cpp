#include <iostream>
#include <vector>
using namespace std;
int f(int n) {
    vector<int> dp(n + 1, 0); 
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2; 
    }
    if (n % 2) { 
        return (dp[n] + dp[n / 2]) / 2;
    }

    return (dp[n] + dp[n / 2] + dp[n / 2 - 1] * 2) / 2;
}
int main() {
    int n; 
    cin >> n;
    cout << f(n);
}
