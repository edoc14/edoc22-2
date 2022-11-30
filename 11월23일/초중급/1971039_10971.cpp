#include <iostream>
using namespace std;

int arr[11][11]; // 비용
int visited[11]; //방문 체크
int m = 987654321;

void dfs(int n, int start, int y, int sum, int cnt) {
    //전부 돌고 다시 처음으로 왔을 때
    if (cnt == n && start == y) {
        if (m > sum)
            m = sum;
        return;
    }

    for (int x = 0; x < n; x++) {
        if (arr[y][x] == 0)
            continue; //못 가는 경우

        if (!visited[y] && arr[y][x] > 0) {
            visited[y] = true; //방문 체크
            sum += arr[y][x];

            if (sum <= m) { // 업데이트
                //[1,2]이었으면 [2,-]로 보내줌.
                dfs(n, start, x, sum, cnt + 1);
            }

            //방문한 기록과 합 초기화
            visited[y] = false;
            sum -= arr[y][x];
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        //각각의 점(도시)에서 시작하는 경우
        dfs(n, i, i, 0, 0);
    }

    cout << m;
    return 0;
}
