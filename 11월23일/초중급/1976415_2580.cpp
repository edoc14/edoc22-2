#include <iostream>

using namespace std;

int sudoku[10][10];

bool check_row[10][10]; // 행 검사 : x행에 숫자 y가 있으면 true
bool check_col[10][10]; // 열 검사 : x열에 숫자 y가 있으면 true
bool check_square[10][10]; // 작은 정사각형 검사 : x번째 작은 정사각형에 숫자 y가 있으면 true

// row행 col열이 속하는 작은 정사각형 구하기
int get_square(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}

// sudoku 출력
void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

// num번째 스도쿠 구하기
bool solve(int num) {
    // 마지막 칸인 경우 -> 출력 후 종료
    if (num == 81) {
        print();
        return true;
    }

    // 행, 열 구하기
    int x = num / 9; int y = num % 9;

    if (sudoku[x][y] != 0) {
        // 수가 있으면 -> 다음 수로 넘어가기
        return solve(num + 1);
    }
    else {
        // 수가 없으면 -> 1~9 검사해서 수 채우기
        for (int i = 1; i <= 9; i++) {
            if (!check_row[x][i] && !check_col[y][i] && !check_square[get_square(x, y)][i]) {
                // 스도쿠 처리
                check_row[x][i] = true;
                check_col[y][i] = true;
                check_square[get_square(x, y)][i] = true;
                sudoku[x][y] = i;

                if (solve(num + 1)) {
                    return true;
                }

                // 다시 돌려놓기 (백트래킹)
                check_row[x][i] = false;
                check_col[y][i] = false;
                check_square[get_square(x, y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }

    return false;
}

int main(void) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];

            // 빈칸이 아닌 경우 처리
            if (sudoku[i][j] != 0) {
                check_row[i][sudoku[i][j]] = true;
                check_col[j][sudoku[i][j]] = true;
                check_square[get_square(i, j)][sudoku[i][j]] = true;
            }
        }
    }

    // 0번 칸부터 채우기 시작
    solve(0);
    return 0;
}