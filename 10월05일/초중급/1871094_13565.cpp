#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> vec;
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};
int n, m;

void bfs(int i, int j) {
    queue<pair<int, int>> que;
    que.push({i, j});
    vec[i][j] = 2; // 시작 지점 전류 표시
    while (!que.empty()) {
        int ii = que.front().first;
        int jj = que.front().second;
        que.pop();
        for (int k = 0; k < 4; k++) { // 상하좌우에 전류가 흐를 곳이 있는지
            int ni = ii + di[k];
            int nj = jj + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || vec[ni][nj] == 1 || vec[ni][nj] == 2) continue; // 범위 밖이거나 1이거나 2이면 다음으로 넘어간다.
            que.push({ni, nj});
            vec[ni][nj] = 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vec.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            vec[i][j] = str[j] - '0';
        }
    }
    for (int i = 0; i < m; i++) { // 바깥쪽 줄 돌면서 탐색 시작
        if (vec[0][i] == 0) { // 전류가 통한다
            bfs(0, i);
        }
    }
    // inner side 쪽 줄 탐색하면서 전류가 있는지 확인
    for (int i = 0; i < m; i++) {
        if (vec[n - 1][i] == 2) { // 전류 있음
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}