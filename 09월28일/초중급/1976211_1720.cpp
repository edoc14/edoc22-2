#include <iostream>
using namespace std;

int N,ans;
int dp[31];

int main() {
    cin>>N;

    //초반 dp 초기화
    dp[0]=0;dp[1]=1;dp[2]=3;

    //dp
    for (int i = 3; i <= N; ++i) {
        dp[i]=dp[i-1]+dp[i-2]*2;
    }

    if(N==1){//N이 1일 때
        ans=1;
    }else if(N%2){ //N이 짝수 일때
        ans=(dp[N]+dp[N/2])/2;
    }else{//N이 홀 수 일때
        ans=(dp[N]+dp[N/2+1])/2;
    }

    cout<<ans;
    return 0;
}
