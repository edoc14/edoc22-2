#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> blank;
bool finish = false;

bool check(int a, int b, vector<vector<int>> &sudoku) {
    //한줄 체크
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][b] == sudoku[a][b] && i != a)
            return false; //행 확인
        if (sudoku[a][i] == sudoku[a][b] && i != b)
            return false; //열 확인
    }

    // 3*3확인
    int sa = (a / 3) * 3;
    int sb = (b / 3) * 3;
    for (int i = sa; i < sa + 3; i++) {
        for (int j = sb; j < sb + 3; j++) {
            if (i == a && j == b)
                continue;
            if (sudoku[i][j] == sudoku[a][b])
                return false; //겹치는거 존재
        }
    }

    //겹치는게 없다면 true반환
    return true;
}

void backtracking(int n, vector<vector<int>> &sudoku) {
    if (n == blank.size()) { //모든 칸 다 채움
        finish = true;
        return;
    }

    // n번째 빈칸 좌표
    int a = blank[n].first;
    int b = blank[n].second;

    for (int i = 1; i <= 9; i++) {
        sudoku[a][b] = i; // 1~9넣어보기
        if (check(a, b, sudoku)) {
            backtracking(n + 1, sudoku);
        };

        if (finish)
            return; //스도쿠 완성 => 계속 리턴
    }

    sudoku[a][b] = 0; //못채우면 되돌리기
    return;
}

vector<vector<int>> solution(vector<vector<int>> sudoku) {
    // blank에 빈 공간 저장
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (sudoku[i][j] == 0)
                blank.push_back(make_pair(i, j));

    backtracking(0, sudoku);
    return sudoku;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //입력
    vector<vector<int>> sudoku(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> sudoku[i][j];

    //문제 해결
    auto output = solution(sudoku);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << output[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}