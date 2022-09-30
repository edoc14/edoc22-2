#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int main() {
    cin>>T;

    while(T--){
        int N; cin>>N;
        int s,t,ans=0;
        vector<bool> visited(N,false); //이동 여부
        vector<pair<int,int>> mov; //이동에 사용되는 복도 구간

        for (int i = 0; i < N; ++i) {
            cin>>s>>t;
            //방 번호 -> 복도 번호로 변환하여 저장
            if(s>t) swap(s,t);
            mov.push_back({(s-1)/2,(t-1)/2});
        }

        //오름차순 정렬
        sort(mov.begin(), mov.end());

        int cnt=0; //이미 이동한 횟수
        while(cnt<N){
            int e=-1; //시작점
            for (int i = 0; i < N; ++i) {
                if(visited[i]) continue;
                if(e>=mov[i].first) continue;
                //동시에 이동할 수 있는 경우
                visited[i]=true;
                e=mov[i].second;
                cnt++;
            }
            ans++; //시간 증가
        }

        cout<<ans*10<<'\n';
    }

    return 0;
}
