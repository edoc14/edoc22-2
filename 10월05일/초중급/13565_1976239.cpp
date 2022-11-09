#include <iostream>
#include <string>
#include <queue>

using namespace std;

int M, N;
char grid[1001][1001]; //'0': ���� o, '1':���� x
int visited[1001][1001] = { 0, }; //0:�湮 x, 1: �湮 o
queue<pair<int, int>> q; //bfs�� queue. q.first = ��, q.second=��
string ans = "NO"; //���� bfs ����� ���� YES�� ����.


int bfs(int startM, int startN, int M, int N) { //bfs�� Ž��. 
	q.push(make_pair(startM, startN)); 	//������ q�� ����
	visited[startM][startN] = 1; 	//������ q�� ����

	while (!q.empty()) { 
		int m = q.front().first;
		int n = q.front().second;
		q.pop();

		if (m >= 0 && m < M && n >= 0 && n < N) {

			if (m == M - 1) { //�� inner side�� ������ �����ϸ� 1�� ����.
				return 1;
			}

			//�����¿���� ��� Ž���Ͽ� grid���� vistied�� ��� 0�̸� q�� ����& visited�� 1�� ����

			//��
			if (visited[m - 1][n] == 0 && grid[m - 1][n] == '0') {
				q.push(make_pair(m - 1, n));
				visited[m - 1][n] = 1;
			}


			//��
			if (visited[m + 1][n] == 0 && grid[m + 1][n] == '0') {
				q.push(make_pair(m + 1, n));
				visited[m + 1][n] = 1;
			}

			//��
			if (visited[m][n - 1] == 0 && grid[m][n - 1] == '0') {
				q.push(make_pair(m, n - 1));
				visited[m][n - 1] = 1;
			}

			//��
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
		if (grid[0][i] == '0') { //outer side ���� ��� 0�������� bfs. 
			if (bfs(0, i, M, N) == 1) { //bfs ���ϰ��� 1, �� inner side ���� �����ϸ� ans�� YES�� ����.
				ans = "YES";
				break;
			}
		}
	}
	//1�� �����ϴ� bfs���� Ž�� ����Ǹ� ans�� ����Ʈ �״�� NO ���.

	cout << ans << endl;
}