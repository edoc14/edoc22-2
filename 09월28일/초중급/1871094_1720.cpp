#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    long long dp[31];
    dp[0] = dp[1] = 1;
    for(int i=2;i<=30;i++){
        dp[i] = dp[i-1]+dp[i-2]*2; // dp[i-1]에 세로 하나 추가하는 경우 + dp[i-2]에 가로 두개나 정사각형을 추가하는 경우
    }
    // dp[n] = 대칭 + 비대칭*2
    // 비대칭 = (dp[n]-대칭)/2 이므로
    // 구하는 값 = 대칭 + 비대칭 = (dp[n] + 대칭)/2
    if(n%2==1){ // 홀수
        // 홀수일 때 대칭은 dp[(n-1)/2] = 가운데 세로 하나 두고, 양쪽에 dp[(n-1)/2]을 두는 경우
        cout<<(dp[n] + dp[(n-1)/2])/2;
    }else{ // 짝수
        // 짝수일 대 대칭은 dp[n/2]+dp[n/2-1]*2 = dp[n/2]를 두번 두는 경우 + 중간에 가로 2개 두고 양쪽에 dp[n/2-1], 중간에 정사각형 두고 양쪽에 dp[n/2-1]...
        cout<<(dp[n]+dp[n/2]+dp[n/2-1]*2)/2;
    }
}