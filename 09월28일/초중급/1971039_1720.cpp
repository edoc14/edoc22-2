#include <algorithm>
#include <iostream>
using namespace std;

/*
    대칭 고려 안하고 1*2, 2*1, 2*2로 타일을 채우는 방법
    => dp[i] = dp[i-1] + dp[i-2]*2
    => 이 경우 (좌우 대칭인 경우)*2 + (좌우 대칭이 아닌 경우) 가 된다.

    ----
    <대칭인 경우>
    1. n이 홀수일 때
        가운데에 1*2을 두고 좌우가 같은 경우

    2. n이 짝수일 때
        가운데에 2*2를 두고 좌우가 같은 경우
        가운데에 2*1 두개를 두고 좌우가 같은 경우

*/
int dp[31];

int main() {
    int n;
    cin >> n;

    dp[0] = dp[1] = 1; //여기서 dp[0]을 설정해주지 않으면 93%에서 틀린다.
    dp[2] = 3;

    //전체 경우
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
    }

    int result;

    if (n % 2 == 0) { //짝수인 경우
        result = (dp[n] + dp[n / 2] + dp[n / 2 - 1] * 2) / 2;
    } else { //홀수인 경우
        result = (dp[n] + dp[(n - 1) / 2]) / 2;
    }

    cout << result;
}