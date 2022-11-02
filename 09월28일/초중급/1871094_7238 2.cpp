#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int>> vec; // <출발 방, 도착 방>
        for(int i=0;i<n;i++){
            int a, b;
            cin>>a>>b;
            if(a>b){ // 무조건 a -> b로 가도록 순서 변경
                int tmp = b;
                b=a;
                a=tmp;
            }
            vec.push_back({a,b});
        }
        int cnt = 0;
        sort(vec.begin(), vec.end()); // 출발 방 번호 기준으로 정렬
        while(!vec.empty()){
            cnt++; // + 10분
            int end = vec[0].second; // vec[0]
            vector<pair<int, int>> newVec;
            int idx=1;
            while(idx<vec.size()){
                if(vec[idx].first<=end||(end%2!=0&&vec[idx].first==end+1)){ // 중첩 옮길 수 없음
                    newVec.push_back(vec[idx++]); // 중첩되는 경우 newVec에 담아서 10분 후 다시 돌면서 확인
                }else{ // 중첩 X = 동시에 옮길 수 있다
                    end = vec[idx++].second; // vec[idx].second로 end값 갱신
                }
            }
            vec = newVec;
        }
        cout<<cnt*10<<'\n';

    }

    return 0;
}