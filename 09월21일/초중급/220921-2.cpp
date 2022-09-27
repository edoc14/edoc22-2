// 이퍼 기출 - 양과 늑대

#include <string>
#include <vector>

using namespace std;

vector<int> ii; // info
vector<vector<int>> vec;
int ans = 0;

void dfs(int idx, vector<int> nxt, int sheep, int wolf){ // 현 노드, 다음 탐색 목록, 양, 늑대
    if(sheep<=wolf){ // 리턴 조건: 늑대가 많거나 같으면
        return;
    }
    ans = max(ans, sheep); // 양 최댓값 갱신
    for(int i=0;i<nxt.size();i++){
        vector<int> tmp;
        tmp = nxt;
        int nIdx = nxt[i]; // 다음 인덱스
        tmp.erase(tmp.begin()+i); // 다음 탐색할 노드는 지우고
        for(auto j: vec[nIdx]) tmp.push_back(j); // 다음 노드와 연결된 노드를 담는다.
        int ns = sheep; int nw = wolf;
        if(ii[nIdx]==0) ns++; // 다음 노드에 양이 있으면 양++
        else nw++; // 늑대면 늑대++
        dfs(nIdx, tmp, ns, nw);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    ii = info;
    vec.assign(info.size(), vector<int>());
    for(auto e: edges){
        vec[e[0]].push_back(e[1]);
    }
    vector<int> nxt;
    for(auto i: vec[0]){ // 0과 연결된 노드 담기
        nxt.push_back(i);
    }
    dfs(0, nxt, 1, 0);

    return ans;
}