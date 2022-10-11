#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int n;
vector<bool> visit;
vector<bool> finish;
int cnt;

void isCycle(int idx){
    visit[idx] = true;
    int nxt = vec[idx];
    if(!visit[nxt]){
        isCycle(nxt);
    }else if(!finish[nxt]){ // 방문 했는데 사이클이 아니면 nxt까지 사이클
        for(int i=nxt;i!=idx;i=vec[i]){ // nxt에서 idx까지 다음으로 넘어가면서 팀원세기
            cnt++;
        }
        cnt++; // 자기자신
    }
    finish[idx] = true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vec.clear();
        vec.assign(n+1,0);
        visit.clear();
        visit.assign(n+1,false);
        finish.clear();
        finish.assign(n+1, false);
        for(int i=1;i<=n;i++){
            cin>>vec[i];
        }
        cnt = 0;
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                isCycle(i);
            }
        }

        cout<<n-cnt<<'\n';
    }

    return 0;
}