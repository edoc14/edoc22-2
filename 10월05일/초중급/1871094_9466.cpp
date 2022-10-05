// 6x% 시간초과

#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int n;

bool isAlone(int idx){
    vector<bool> visit(n+1,false);
    int start = idx;
    visit[start] = true;
    int nxt = vec[idx];
    while(true){
        if(nxt==start) return false; // 사이클 생성
        if(nxt==vec[nxt]||visit[nxt]) return true; // 다음 사람이 자기 자신을 선택하거나 다음 사람은 이미 방문한 사람
        visit[nxt] = true;
        nxt = vec[nxt];
    }
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
        for(int i=1;i<=n;i++){
            cin>>vec[i];
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(isAlone(i)) cnt++;
        }
        cout<<cnt<<'\n';
    }

    return 0;
}