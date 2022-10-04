// 이퍼 기출 - 합승 택시 요금

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7 * 2; // 최대 n-1개의 간선을 지나게 됨

int solution(int n, int s, int a, int b, vector<vector<int>> fares, int lay) {
    int answer = 1e9;

    // 비용 계산할 이차원 벡터, cost[i][j] = i에서 j까지의 비용
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) { // i 부터 i까지의 비용은 0
        cost[i][i] = 0;
    }
    for (auto f: fares) { // fares를 돌면서 cost에 비용 표시하기
        cost[f[0]][f[1]] = cost[f[1]][f[0]] = f[2];
    }
    // 플로이드 와샬
    for (int i = 1; i <= n; i++) { // 거쳐가는 지점
        for (int j = 1; j <= n; j++) { // 출발지
            for (int k = 1; k <= n; k++) { // 도착지
                // j -> k 와 j -> i -> k 비교해서 최솟값 갱신
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[k][i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        // 출발지(s) -> 경유지(lay) -> 경유지(i) 더하기 i에서 A의 집까지 비용 더하기 i에서 B까지 비용
        answer = min(answer, cost[s][lay] + cost[lay][i] + cost[i][a] + cost[i][b]);
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
        fares.push_back({ u,v,w });
    }

    int ans = solution(n, s, a, b, fares, c);
    cout << ans;
}