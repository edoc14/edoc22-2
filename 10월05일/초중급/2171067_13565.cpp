#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

stack<pair<int,int>> s;
char g[1000][1000];
bool visited[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int m, n;

int dfs(int x, int y) {
	if (x == m - 1) {
		cout << "YES";
		exit(0);
	}
	x = s.top().first;
	y = s.top().second;
	s.pop();

	//cout <<"2. " << x << " " << y << "\n";
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < m && 0 <= ny && ny < n) {
			if (g[nx][ny] == '0' && !visited[nx][ny]) {
				s.push(make_pair(nx, ny));
				visited[x][y] = true;
				dfs(nx, ny);
				visited[nx][ny] == false;
			}
		}
	}
	return 0;

}

int main() {

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (g[0][i] == '0') {
			s.push(make_pair(0, i));
			visited[0][i] = true;
			if (dfs(0, i)) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}