#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cost = 0, n;
vector<vector<int>> w;
vector<bool> visited;

// n번째 도시에서 출발
void solve(int idx, int cnt, int sum) {

	// 도시 다 돌았으면 끝
	if (cnt == n - 1) {
		if (w[idx][0] == 0)
			return;
		else
			sum += w[idx][0];

		if (cost == -1 || cost > sum) {
			cost = sum;
		}

		return;
	}

	for (int i = 1; i < n; i++) {
		
		if (visited[i])
			continue;

		if (w[idx][i] == 0)
			continue;

		visited[i] = true;
		solve(i, cnt+1, sum + w[idx][i]);

		visited[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	w.assign(n, vector<int>(n, 0));
	visited.assign(n, false);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	}

	cost = -1;

	visited[0] = true;
	solve(0, 0, 0);

	cout << cost << "\n";

	return 0;
}