#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int m, n, x, y;
vector<vector<int>> board;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;
bool isPossible = false;

void check(int a, int b) {
	
	//cout << "(a, b) = (" << a << ", " << b << ") -> ";

	q.push({ a, b });
	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		//cout << "(x, y) = (" << x << ", " << y << ")\n";
		if (x == m - 1) {
			isPossible = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//cout << "(nx, ny) = (" << nx << ", " << ny << ")\n";
			// board 안에 있으면
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (board[nx][ny] == 0) {
					//cout << "(nx, ny) = (" << nx << ", " << ny << ")\n";
					board[nx][ny] = 2;
					q.push({ nx, ny });
				}	
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> m >> n;
	board.assign(m, vector<int>(n, 0));

	string input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		for (int j = 0; j < n; j++) {
			board[i][j] = input[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		if (board[0][i] == 0) {
			//cout << "--------------\n";
			check(0, i);
		}
	}


	// 출력
	if (isPossible)
		cout << "YES\n";
	else
		cout << "NO\n";


	return 0;
}