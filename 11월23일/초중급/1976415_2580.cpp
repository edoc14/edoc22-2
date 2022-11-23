#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int check_row[9][10] = { 0, };
int check_col[9][10] = { 0, };
int check_square[9][10] = { 0, };

vector<vector<int>> board(9, vector<int>(9, 0));
vector<vector<int>> answer(9, vector<int>(9, 0));

vector<pair<int, int>> blank_position;

int find_square(int i, int j) {
	int a = 0, b = 0;
	switch (i) {
	case 0:
	case 1:
	case 2:
		a = 0;
		break;
	case 3:
	case 4:
	case 5:
		a = 3;
		break;
	case 6:
	case 7:
	case 8:
		a = 6;
		break;
	}
	
	switch (j) {
	case 0:
	case 1:
	case 2:
		b = 0;
		break;
	case 3:
	case 4:
	case 5:
		b = 1;
		break;
	case 6:
	case 7:
	case 8:
		b = 2;
		break;
	}
	return a + b;
}

bool backtracking(int cur, int size) {
	// ��ĭ �� ä��
	if (cur == size) {
		return true;
	}

	int row = blank_position[cur].first;
	int col = blank_position[cur].second;
	int square = find_square(row, col);

	// �� ĭ�� 1���� 9���� �־ ���� �����ϴ��� check
	for (int num = 1; num < 10; num++) {
		// �ϴ� ��ġ�� ���ڰ� ����, ����, �簢�� ���� ������
		if (!check_row[row][num] && !check_col[col][num] && !check_square[square][num]) {
			// �켱 1�� check ǥ��
			check_row[row][num] = 1;
			check_col[col][num] = 1;
			check_square[square][num] = 1;

			// ���� ĭ ä���
			answer[row][col] = num;

			if (backtracking(cur + 1, size)) {
				return false; // ����
			}
			// �ʱ�ȭ
			check_row[row][num] = 0;
			check_col[col][num] = 0;
			check_square[square][num] = 0;
			answer[row][col] = 0;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];
	}

	answer.assign(board.begin(), board.end()); // answer�� ���� ���� ����
	// ���� ���� check
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			// ��ĭ�̸� blank_position�� ��ǥ �߰�
			if (board[i][j] == 0) {
				blank_position.push_back({ i, j });
			}
			// �ƴϸ� check �迭�鿡 1 ǥ��
			else {
				check_row[i][board[i][j]] = 1;
				check_col[j][board[i][j]] = 1;
				check_square[find_square(i, j)][board[i][j]] = 1;
			}
		}
	}

	backtracking(0, blank_position.size());

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << answer[i][j] << " ";
		cout << "\n";
	}

	return 0;
}