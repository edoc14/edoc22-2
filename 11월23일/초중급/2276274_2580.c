#include<stdio.h>

int cant = 0;

void Sudoku(int sudoku[][9]) {
	for (int row = 0; row < 9; row++) { // 행 돌리기
		for (int col = 0; col < 9; col++) { // 열 돌리기
			if (sudoku[row][col] == 0) { // 스도쿠[행][열]==0이면
				int num[10] = { 0 };
				for (int j = 0; j < 9; j++) { // 행 검사
					num[sudoku[row][j]] = 1;
				}
				for (int j = 0; j < 9; j++) { // 열 검사
					num[sudoku[j][col]] = 1;
				}
				for (int j = 0; j < 3; j++) { // 칸 검사
					for (int k = 0; k < 3; k++) {
						num[sudoku[row / 3 * 3 + j][col / 3 * 3 + k]] = 1;
					}
				}
				for (int j = 1; j <= 9; j++) { // 없는 수 삽입
					if (num[j] == 0) {
						sudoku[row][col] = j;
						Sudoku(sudoku);
						if (cant == 1) {
							sudoku[row][col] = 0;
							cant = 0;
						}
						else return;
					}
				}
				if (sudoku[row][col] == 0) {
					cant = 1;
					return;
				}
			}
		}
	}
}

int main() {
	int sudoku[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &sudoku[i][j]);
	Sudoku(sudoku);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", sudoku[i][j]);
		puts("");
	}
	return 0;
}
