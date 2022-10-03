#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_ROOM=401;
typedef pair<int, int> ti;
int time_count(vector<ti> move, int n) { //옮기는 데 걸리는 시간 리턴
    vector<int> dp(MAX_ROOM, 0);    //겹치는 방 개수 저장
    for(int i=0; i<n; i++) {
        for(int room=move[i].first; room<=move[i].second; room++) {
            dp[room]++;
        }
    }
    //걸리는 시간 = 가장 많이 겹치는 방 개수 * 10
    return *max_element(dp.begin(), dp.end())*10;   
}
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<ti> move(n);
        for(int i=0; i<n; i++) {
            int s, t;
            cin>>s>>t;
            s=(s-1)/2;
            t=(t-1)/2;  //1~2/3~4/.../399~400은 같은 복도 
            if(s>t) {
                swap(s, t); //s가 무조건 작도록 설정
            }
            move[i]={s, t};
        }

        cout<<time_count(move, n)<<'\n';
    }
}