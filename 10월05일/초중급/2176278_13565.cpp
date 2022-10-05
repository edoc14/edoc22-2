#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 }; // → ← ↓ ↑

int main() {
	/*입력받기*/
	int M, N;
	cin >> M >> N;

	vector<vector<int>> arr(M); //격자 저장
	vector<vector<bool>> visited(M);
	stack<pair<int, int>> st;

	for (int i = 0; i < M; i++) {
		visited[i].assign(N, false); //초기화
		arr[i].resize(N);

		int input;
		cin >> input;
		for (int j = N - 1; j >= 0; j--) {
			arr[i][j] = input % 10;
			input /= 10;
		}
	}


	/*해결하기*/
	for (int j = 0; j < N; j++) { //가장 바깥쪽 줄 (i은 0으로 고정)
		if (arr[0][j] != 0) { //검은색 격자이면
			continue;
		}

		//흰색 격자이면 거기에서부터 DFS
		visited[0][j] = true;
		st.push({ 0, j });
		while (!st.empty()) {
			int rr = st.top().first;
			int cc = st.top().second;
			st.pop();

			for (int k = 0; k < 4; k++) {
				int nr = rr + dr[k];
				int nc = cc + dc[k];

				if (nr < 0 || nc < 0 || nr >= M || nc >= N) //격자 범위 벗어나면
					continue;
				if (arr[nr][nc] != 0 || visited[nr][nc]) //검은색이거나, 방문한 격자이면
					continue;

				if (nr == M - 1) { //전류가 가장 안쪽까지 도달한 경우
					cout << "Yes" << "\n";
					return 0; //프로그램 종료
				}
				visited[nr][nc] = true;
				st.push({ nr, nc });
			}
		}
	}

	cout << "No" << "\n";

	return 0;
}
