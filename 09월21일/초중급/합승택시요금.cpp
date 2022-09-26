#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e7 * 2; // 최대 n-1개의 간선을 지나게 됨
int graph[202][202]={0,};

int solution(int n, int s, int a, int b, vector<vector<int>> fares, int lay) {
	int answer = INF;
	
	//1. i-j지점 사이의 예상택시요금을 원소로 갖는 2차원 벡터 graph 생성 및 INF로 초기화
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			graph[i][j] = INF;
		}
		graph[i][i]=0;
	}
	
	//2. fares 배열값 graph에 저장 ([i][j], [j][i] 둘 다에 대칭적으로 저장
	for (int i = 0; i<fares.size(); i++){
			graph[fares[i][0]][fares[i][1]] = fares[i][2];
			graph[fares[i][1]][fares[i][0]] = fares[i][2];
	}
	
	//3. 플로이드 워셜 알고리즘. 
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
				//i-j직행 최단간선과, k를 경유하는 (i-k최단경로)+(k-j최단경로)의 비용을 비교하여
				//더 작은 값을 i-j최단경로 비용으로 저장함.
			}
		}
	}
	
	//4. 최소비용
	for (int i =1; i<=n;i++){
		answer = min(answer, graph[s][lay]+graph[lay][i]+graph[i][a]+graph[i][b]);
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
	return 0;
}