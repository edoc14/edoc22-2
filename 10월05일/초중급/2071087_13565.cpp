#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N, M;
const int MAX = 1001;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void DFS(int  y, int x) { //깊이 우선 탐색
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) { //방향 확인
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N)
            continue;
        if (map[ny][nx]==0 && !visited[ny][nx]) {
            visited[ny][nx] = true; //방문 확인하면 true
            DFS(ny, nx);
        }
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int j = 0; j < N; j++) {
        if (map[0][j]==0 && !visited[0][j]) {
            DFS(0, j);
        }
    }

    bool flag = false;
    for (int j = 0; j < N; j++) {
        if (visited[M-1][j]) {
            flag = true;
        }
    }

    if (flag == true)
        cout << "YES";
    else
        cout << "NO";
}
