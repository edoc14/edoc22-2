#include <stdio.h>
 
int dp[31], dp2[31];
int main()
{
    int N, i, tmp;
    scanf("%d",&N);                   // 판의 총 가로길이

    dp[1]=1,dp[2]=3;
    for(i=3;i<=N;i++)
        dp[i]=dp[i-2]*2+dp[i-1];      //좌우 대칭이 아닌 경우
    
    dp2[1]=1,dp2[2]=3;
    for(i=3;i<=N;i++){                //좌우대칭인 경우
       if(i&1)                        //n이 홀수인 경우
           tmp = dp[(i - 1)/2];       //중간에 1x2가 들어가는 경우
        else                          //n이 짝수인 경우
            tmp=dp[i/2]+(2*dp[(i-2)/2]);    //완전히 절반으로 나누는 경우, 중간에 2x1 두 개나 2x2 한 개가 들어가는 경우
        
        dp2[i]=(dp[i]+tmp)/2;
    }
    printf("%d",dp2[N]);
    return 0;
}
