/*
처음에는 이동을 정렬한 뒤, 앞에서부터 하나의 이동과 겹치지 않는 이동을 지워나가는 식으로 진행했다.
백준 사이트의 예제로는 잘 돌아가는데 틀렸습니다!가 뜸..
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v;

int main(){
    int T,N,a,b;
    cin>>T;
    
    while(T>0){
    int ans=0;
    pair<int, int> p;
    cin>>N;
    for(int k=0;k<N;k++){
        cin>>a>>b;
        a=(a+1)/2; b=(b+1)/2;
        if(a<b) {p=make_pair(a,b);}     //번호가 낮은 쪽이 앞에 오도록
        else{p=make_pair(b,a);}
        v.push_back(p);
    }
    sort(v.begin(),v.end());            //정렬
    
    int end;        
    int finish=0;                       //완료시킨 이동 수
    while(finish<N){                    //모든 이동을 완료하면 끝
    int i=0;
    for(;i<N;i++){
        if(v[i].first!=-1){             //아직 완료하지 않은 이동 중 가장 앞쪽에서 시작되는 이동 찾기
            end=v[i].second;
            v[i].first=-1;v[i].second=-1;
            break;
        }
    }
    for(int j=i+1;j<N;j++){             
        if(v[j].first>end){                 //다음 이동과 겹치지 않는다면, 동시에 진행할것임
            end=v[j].second;                //현재 진행중인 이동들이 사용하는 복도 중 가장 끝지점 업데이트
            v[j].first=-1;v[j].second=-1;   //이동을 완료했으므로 -1로 저장
            finish++;                       //완료한 이동 개수+1
        }
    }
    finish++;
    ans++;                                  //동시에 완료할수 있는 이동 모두 완료 후 ans에+1
    }
    
    cout<<ans*10;
    T--;
    }
    return 0;
}   
*/

//여러 이동 시 겹치는 복도는 동시에 이동할 수 없다
//즉, 이동이 가장 많이 겹치는 복도의 이동이 겹치는 수만큼의 시간이 걸린다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100];

int main(){
    int T,N,a,b;
    cin>>T;
    while(T>0){
    for(int i=0;i<200;i++){
        dp[i]=0;                //dp 초기화
    }
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        a=(a+1)/2; b=(b+1)/2;   //1,2/3,4/5,6/.../399,400이 같은 복도 사용
        if(a>b) {
            int temp=a;         //출발지점의 복도가 더 뒷쪽이면 바꿔준다
            a=b;
            b=temp;
        }
        for(int j=a;j<=b;j++){
            dp[j]++;            //이동 시 사용하는 복도에 모두 +1
        }
    }
    int ans=-1;
    for(int i=0;i<200;i++){
        if(ans<dp[i])ans=dp[i]; //이동이 가장 많이 겹친 복도 찾기
    }
    
    cout<<ans*10<<'\n';
    T--;
    }
    return 0;
}   