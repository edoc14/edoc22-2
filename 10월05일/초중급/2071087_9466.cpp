#include <iostream>
#include <cstring> //memset
#define MAX 100001
using namespace std;

int t, n;
int graph[MAX];
bool visited[MAX];
bool done[MAX]; //방문이 끝났는지 여부
int cnt;
void hasCycle( int node) {

    visited[node] = true;
    int next = graph[node];

    if (!visited[next]) {
        hasCycle( next);
    }
    //방문은 했지만 아직 사이클이 아니라면 next까지 포함해서 사이클 완성
    else if (!done[next]) {
        //자기 자신을 포함한 팀의 멤버를 카운트
        for (int i = next; i != node; i = graph[i]) {
            cnt++;
        }
        cnt++; //자기 자신을 센다.
    }
    done[node] = true; //더 이상 해당 노드 방문할 일이 없다.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> graph[i];
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                hasCycle(i); //팀을 이루는 사람들을 센다.
            }
        }
        cout << n-cnt << '\n';
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
    }
    return 0;
}

//코드 출처:https://ongveloper.tistory.com/167