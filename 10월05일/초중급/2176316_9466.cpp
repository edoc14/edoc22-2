#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define n_ 100001
using ll=long long;
using namespace std;

ll V,E,n,m,a,b,c,d,x,y,cnt;
ll dfsn[n_],SN,sn[n_]; //dfsn : 방문 순서를 저장하는 배열 , SN: SCC Number , sn[] i번 정점을 포함하는 SCC 번호
vector<ll> in_dg(n_); // 번호, 인디그리 수
vector<ll> v[n_];
stack<ll> st;
bool fin[n_];// i번째 정점에서 SCC 추출이 끝났는 지 확인하는 배열


ll dfs(ll x){
dfsn[x]=++cnt; //방문순서 저장
st.push(x);
ll ret=dfsn[x];
for(ll nxt : v[x]){
if(!dfsn[nxt]) ret=min(ret,dfs(nxt)); //방문 안 했으면 방문하기 최소로 하는 이유는 front edge, cross edge 무시
else if(!fin[nxt]) ret=min(ret,dfsn[nxt]); //방문했지만 끝나지 않았으면 (back edge) 방문하기
}
if(ret == dfsn[x]){ // 더 이상 위로 올라갈 수 없다
while(1){
  ll a=st.top();
  st.pop();
  fin[a] = true; //true
  sn[a] = SN;
  if(a == x) break; 
}
  SN++;
}
return ret;
}
void init(){
    memset(fin,0,sizeof(fin));
    memset(dfsn,0,sizeof(dfsn));
    memset(sn,0,sizeof(0));
    in_dg.clear();
    in_dg.resize(n_);
    cnt = 0;
    SN = 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1; cin>>tc;
    while(tc--){
    //init
    int answer = 0;
    init();
    cin>>V;
    for(int i = 1; i <= V; i++) v[i].clear();
    for(int i = 1; i <= V; i++){
    cin>>a;
    if(i == a) continue;
    v[a].push_back(i); //단방향 그래프
  }
    for(int i = 1; i <= V; i++)  if(!dfsn[i]) dfs(i); // 방문하지 않았으면 방문한다
    cout<<SN;
    cout<<V-SN<<'\n';
    for(int i = 1; i <= V; i++) cout<<sn[i]<<" ";
 }

}
