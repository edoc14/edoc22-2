#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[]){
    check[start]=true;

    for (int i = 0; i < graph[start]; i++) {
        int next = v[start][i];

        if (!check[next]){
            dfs(next, graph, check);
        }
    }
}

int main() {
    int m,n;
    cin >> m>> n;

    vector<int>graph[n+1];

    for (int i = 0; i <m; i++) {
        int u,v;
        for (int j = 0; j < n; j++) {
            cin>>
        }
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs();
    return 0;

    /*
     * 2차원 배열 입력 받고
     * x[0][j] j 1~n까지 반복
     * 1인 경우 i++
     * 예를 들어 x[0][1] = 1이다.
     * x[1][1] 이 1인지 확인 -> 1이면 양옆 1인지 확인
     * x[1][1] 이 0이면 x[0][2], x[0][3] 반복문 계속
     * x[1][1] 1이면 x[1][j-1]과 x[1][j+1]이 1인지 확인 -> 이과정 반복
     * x[m][j] 도달 후, 1이 하나라도 있으면, 반복문 종료 후 "YES" 출력
     * x[m][j] 도달 후, 0 뿐이면 "NO" 출력
     */
}
