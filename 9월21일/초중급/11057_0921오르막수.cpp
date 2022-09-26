#include <iostream>
using namespace std;

int dp[1000][10];
/*dp[i][j]: j로 끝나는 i자리수의 오르막 수의 개수
표를 작성해보니 dp[i][j]=dp[i-1][j]+dp[i][j-1]라는 규칙이 나타났다

이는 dp[i][j-1]에서 마지막 수만 j로 바꾼것과 
dp[i-1][j]의 맨 뒤(일의자리)에 j를 추가한 것이 dp[i][j]의 전부이기 떄문이다
*/

int main()
{
    int N;
    cin>>N;
    
    for(int i=0;i<10;i++){
        dp[1][i]=1;         //dp[1][j]: 한자리 수 오르막수는 모두 1 고정 
    }
    for(int i=2;i<=N;i++){  //dp[i][j]=dp[i-1][j]+dp[i][j-1]
        dp[i][0]=1;
        for(int j=1;j<10;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=10007;    //여기서 나머지 연산을 안해주면 틀렸다고 뜬다. 이유가뭘까..?
        }
    }
    int sum=0;
    for(int i=0;i<10;i++){  //i자리 수의 오르막수 개수의 총합은 0~9로 끝나는 모든 경우의 합
        sum+=dp[N][i];
    }
    cout<<sum%10007;        //답을 10007로 나눈 값을 출력
    return 0;
}
