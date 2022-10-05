#include <iostream>
#include <string>
#include <queue>

using namespace std;

int M, N;
char grid[1001][1001]; //'0': 전류 o, '1':전류 x
int visited[1001][1001] = { 0, }; //0:방문 x, 1: 방문 o
queue<pair<int, int>> q; //bfs용 queue. q.first = 행, q.second=열
string ans = "NO"; //이후 bfs 결과에 따라 YES로 갱신.


int bfs(int startM, int startN, int M, int N) { //bfs로 탐색. 
	q.push(make_pair(startM, startN)); 	//시작점 q에 삽입
	visited[startM][startN] = 1; 	//시작점 q에 삽입

	while (!q.empty()) { 
		int m = q.front().first;
		int n = q.front().second;
		q.pop();

		if (m >= 0 && m < M && n >= 0 && n < N) {

			if (m == M - 1) { //즉 inner side에 도달이 성공하면 1을 리턴.
				return 1;
			}

			//상하좌우방향 노드 탐색하여 grid값과 vistied값 모두 0이면 q에 삽입& visited값 1로 갱신

			//상
			if (visited[m - 1][n] == 0 && grid[m - 1][n] == '0') {
				q.push(make_pair(m - 1, n));
				visited[m - 1][n] = 1;
			}


			//하
			if (visited[m + 1][n] == 0 && grid[m + 1][n] == '0') {
				q.push(make_pair(m + 1, n));
				visited[m + 1][n] = 1;
			}

			//좌
			if (visited[m][n - 1] == 0 && grid[m][n - 1] == '0') {
				q.push(make_pair(m, n - 1));
				visited[m][n - 1] = 1;
			}

			//우
			if (visited[m][n + 1] == 0 && grid[m][n + 1] == '0') {
				q.push(make_pair(m, n + 1));
				visited[m][n + 1] = 1;
			}
		}
	}
	
	return 0;
}

int main() {
	cin >> M >> N;

	string input;
	for (int i = 0; i < M; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			grid[i][j] = input[j];
		}
	}

	for (int i = 0; i < N; i++) { 
		if (grid[0][i] == '0') { //outer side 행의 모든 0에서부터 bfs. 
			if (bfs(0, i, M, N) == 1) { //bfs 리턴값이 1, 즉 inner side 도달 성공하면 ans값 YES로 갱신.
				ans = "YES";
				break;
			}
		}
	}
	//1을 리턴하는 bfs없이 탐색 종료되면 ans값 디폴트 그대로 NO 출력.

	cout << ans << endl;
}