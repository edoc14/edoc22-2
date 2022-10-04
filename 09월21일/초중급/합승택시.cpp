#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e7 * 2; // 최대 n-1개의 간선을 지나게 됨

int graph[201][201] = {
    0,
};

int solution(int n, int s, int a, int b, vector<vector<int>> fares, int lay) {
    int answer = INF;

    // 1. nxn 배열의 모든 원소를 INF로 채워 넣는다. (자기 자신은 0으로)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
        graph[i][i] = 0; //자기 자신과의 비용은 0
    }

    // 2. 주어진 입력값으로 초기화를 합니다.
    for (int i = 0; i < fares.size(); i++) {
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    // 3. 플로이드-워셜을 적용
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] =
                    min(graph[i][j], graph[i][k] + graph[k][j]); // k 지점을 지나는 것이 더 저렴할 경우 업데이트
            }
        }
    }

    // 4. 최소 비용 계산
    // lay는 경유지
    for (int i = 1; i <= n; i++) {
        answer = min(answer, graph[s][lay] + graph[lay][i] + graph[i][a] + graph[i][b]);
    }

    return answer;
}

int main() {
    int n, s, a, b, c, u, v, w;
    cin >> n >> s >> a >> b >> c;

    // 테스트 케이스 개수 : 9
    int i = 9;
    vector<vector<int>> fares;
    while (i--) {
        cin >> u >> v >> w;
        fares.push_back({u, v, w});
    }

    int ans = solution(n, s, a, b, fares, c);
    cout << ans;
}