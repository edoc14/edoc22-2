#include <algorithm>
#include <iostream>
using namespace std;

int xx[4] = {1, -1, 0, 0}; //방향 이동
int yy[4] = {0, 0, 1, -1};

string arr[1001];
bool visited[1001][1001];

// dfs
void dfs(int y, int x, int m, int n) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int py = yy[i] + y;
        int px = xx[i] + x;

        if (py < 0 || py >= m || px < 0 || px >= n) //범위가 넘어가는 경우
            continue;
        if (arr[py][px] == '0' && !visited[py][px]) {
            dfs(py, px, m, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //입력
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    //문제 해결
    for (int j = 0; j < n; j++) {
        if (arr[0][j] == '0' && !visited[0][j]) {
            dfs(0, j, m, n);
        }
    }

    //결과 체크 및 출력
    for (int j = 0; j < n; j++) {
        if (visited[m - 1][j]) {
            cout << "YES";
            return 0; //하나라도 나갈 수 있으면 바로 종료
        }
    }

    cout << "NO"; //전부 체크했는데 안되면 NO
}