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
	// 빈칸 다 채움
	if (cur == size) {
		return true;
	}

	int row = blank_position[cur].first;
	int col = blank_position[cur].second;
	int square = find_square(row, col);

	// 빈 칸에 1부터 9까지 넣어서 조건 충족하는지 check
	for (int num = 1; num < 10; num++) {
		// 일단 겹치는 숫자가 가로, 세로, 사각형 내에 없으면
		if (!check_row[row][num] && !check_col[col][num] && !check_square[square][num]) {
			// 우선 1로 check 표시
			check_row[row][num] = 1;
			check_col[col][num] = 1;
			check_square[square][num] = 1;

			// 정답 칸 채우기
			answer[row][col] = num;

			if (backtracking(cur + 1, size)) {
				return false; // 종료
			}
			// 초기화
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

	answer.assign(board.begin(), board.end()); // answer에 현재 상태 저장
	// 현재 상태 check
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			// 빈칸이면 blank_position에 좌표 추가
			if (board[i][j] == 0) {
				blank_position.push_back({ i, j });
			}
			// 아니면 check 배열들에 1 표시
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