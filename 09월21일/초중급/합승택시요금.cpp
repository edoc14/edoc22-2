#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e7 * 2; // 최대 n-1개의 간선을 지나게 됨

//가중치 그래프, 무향

	/*
	경로를 쪼개보면
		s -> c
		c -> 합승지점
		합승지점 -> a
		합승지점 -> b
	얘네 최저 요금을 다 더하면 = 총 요금.

	근데 여기서 합승지점이 미지수. x라 하자.
	총 요금 d(x)
	d(x) 중 최솟값을 같으면? 그게 정답.

	다익스트라 : 시작점 ~ 모든 정점 최단경로 구하기
	근데 매번 구하면 낭비잖아. DP 써야겠다.
		dist배열을 이차원 배열로 만들어서 저장하자.

	(다익스트라로 안 하고, 모든 정점 ~ 모든 정점 최단경로 구하는 "플로이드-워셜"알고리즘을 쓸 수도 있다.)
	(https://chanhuiseok.github.io/posts/algo-50/)

	근데 각각의 최단경로를 다익스트라로 구하면 --> 시간복잡도 O(n^3 logn)
	n <= 200이니까 연산량 5천만..? 시간제한 1초쯤은 견디겠지?
	*/

int solution(int n, int s, int a, int b, vector<vector<int>> fares, int c) {
	int answer = 0;

	vector<pair<int, int>> adj[201];
	int dist[201][201]; //시작점 r ~ 도착점 c 최단 거리

	/*dist 배열 초기화*/
	for (int i = 0; i < 201; i++)
		for (int j = 0; j < 201; j++)
			dist[i][j] = INF;

	/*fares --> 인접 리스트로 변환*/
	for (int i = 0; i < (int)fares.size(); i++) {
		adj[fares[i][0]].push_back({ fares[i][1], fares[i][2] });
		adj[fares[i][1]].push_back({ fares[i][0], fares[i][2] });
	}

	/*모든 정점 ~ 모든 정점 최단경로 구하기*/
	for (int start = 1; start <= n; start++) { //모든 노드를 시작점으로
		//다익스트라
		vector<int> visited(n + 1); //자동으로 0으로 초기화.
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ; //{시작점~ 거리, 도착점}

		dist[start][start] = 0;
		PQ.push({ 0, start });
		while (!PQ.empty()) {
			int curr;

			do {
				curr = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[curr]);
			if (visited[curr]) break;

			visited[curr] = 1;
			for (auto a: adj[curr]) {
				int next = a.first;
				int d = a.second;
				if (dist[start][next] > dist[start][curr] + d) {
					dist[start][next] = dist[start][curr] + d;
					PQ.push({ dist[start][next], next });
				}
			}
		}
	}

	/*d(x) 하나씩 구하면서 최솟값 갱신*/
	answer = INF;
	for (int x = 1; x <= n; x++) { //A와 B는 x까지 합승함.
		answer = min(answer, dist[s][c] + dist[c][x] + dist[x][a] + dist[x][b]);
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
