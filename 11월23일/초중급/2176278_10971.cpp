#include <iostream>
#define MAX 1e9;
using namespace std;

int N, w[10][10]; //총 나라 개수, 가중치 저장
int minCost = MAX; //최소 비용 (cost 중 최솟값)
bool visited[10] = { false, };

void dfs(int start, int curr, int cnt, int cost) {
	if (cnt == N) { //base case
		//돌아갈 수 있으면, 출발점으로 다시 돌아가기
		if(w[curr][start] != 0 && minCost > cost + w[curr][start])
			minCost = cost + w[curr][start];
		return;
	}

	for (int next = 0; next < N; next++) {
		if (visited[next] || w[curr][next] == 0)
			continue;

		visited[curr] = 1;

		dfs(start, next, cnt + 1, cost + w[curr][next]);

		// 원상복구
		visited[curr] = 0;
	}
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		visited[i] = 1;
		dfs(i, i, 1, 0); //시작점, 현재 위치, 지나온 나라 수, 여태까지의 비용
		visited[i] = 0;
	}

	cout << minCost;

	return 0;
}
