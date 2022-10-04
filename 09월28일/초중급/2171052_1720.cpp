#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N;
    int dp[30];
    cin>>N;
    dp[0]=1; dp[1]=1;
    for(int i=2;i<=N;i++){
        dp[i]=dp[i-1]+dp[i-2]*2;    //dp[i-1]에 1x2추가 dp[i-2]에 2x2추가 또는 2x1 두개 추가 
    }
    
    //완전히 대칭인 경우 뒤집었을 때 겹치지 않는다
    //(대칭이 아닌경우/2)+대칭인 경우=(전체-대칭인 경우)/2+대칭인 경우
    //따라서 (전체+대칭인 경우)/2를 구하면 된다
    
    if(N%2==0){         //짝수
        cout<<(dp[N]+dp[N/2]+dp[N/2-1]*2)/2<<"\n";
        //대칭인 경우: 완전히 절반으로 나뉘는 경우 : dp[n/2]
        //              중간에 2x1 두개 또는 2x2 한개:dp[n/2-1]*2
    }
    else{               //홀수
        cout<<(dp[N]+dp[(N-1)/2])/2<< "\n";
        //대칭인 경우: 가운데 1x2 타일, 좌우 똑같이 dp[(n-1)/2]
    }
    return 0;
}   