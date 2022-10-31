#include <algorithm>
#include <iostream>
using namespace std;

int arr[100002];
bool visited[100002];
bool done[100002]; //사이클 체크 - 확실히 더이상 방문하지 않을 때 true
int cnt;

void dfs(int student) {
    visited[student] = true;

    int nxt = arr[student];
    if (!visited[nxt]) {
        dfs(nxt);
    } else if (!done[nxt]) { //방문은 했는데, 사이클이 끝나진 않았다면
        for (int i = nxt; i != student; i = arr[i])
            cnt++; //팀원 카운
        cnt++;     //자기 자신
    }

    done[student] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //입력
    int t;
    cin >> t;

    while (t--) {
        //입력
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        cnt = 0;                               // 반드시 매번 초기화 해줘야 함
        fill(visited, visited + n + 1, false); // 반드시 매번 초기화 해줘야 함
        fill(done, done + n + 1, false);       // 반드시 매번 초기화 해줘야 함

        //문제 해결
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        //결과 출력
        cout << n - cnt << '\n';
    }
}