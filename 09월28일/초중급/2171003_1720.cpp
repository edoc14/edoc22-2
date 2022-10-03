#include <iostream>
#include <vector>
using namespace std;
int count_tile(int n) {
    vector<int> dp(n+1, 0); //2*n 타일 만들 수 있는 경우의 수 저장
    dp[0]=1; dp[1]=1;
    for(int i=2; i<=n; i++) {
        dp[i]=dp[i-1]+dp[i-2]*2;    // |, =, || 이 붙는 경우
    }
    if(n%2) { // 1) 가로가 홀수인 경우
        return (dp[n]+dp[n/2])/2;   //좌우대칭인 경우 + 회전했을 때 좌우대칭인 경우
    }
    // 2) 가로가 짝수인 경우
    return (dp[n]+dp[n/2]+dp[n/2-1]*2)/2;
}
int main() {
    int n; cin>>n;
    cout<<count_tile(n);
}