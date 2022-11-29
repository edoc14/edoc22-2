#include <iostream>
#include <vector>

using namespace std;

int sdoqu[9][9];
vector<pair<int, int>> v_empty;
int cnt = 0; // 빈 칸의 총 개수
bool is_full = false; // 스도쿠 다 채웠나

bool check(pair<int, int> p){
    for (int i = 0; i < 9; i++) {
        // 가로 : 같은 행에 같은 숫자가 있으면
        if (sdoqu[p.first][i] == sdoqu[p.first][p.second] && i != p.second)
            return false;
        // 세로 : 같은 열에 같은 숫자가 있으면
        if (sdoqu[i][p.second] == sdoqu[p.first][p.second] && i != p.first)
            return false;
    }

    // 작은 사각형 : 같은 구역에 같은 숫자가 있으면
    int square_x = p.first / 3;
    int square_y = p.second / 3;
    for (int i = 3 * square_x; i < 3 * square_x + 3; i++)
        for (int j = 3 * square_y; j < 3 * square_y + 3; j++) {
            if (sdoqu[i][j] == sdoqu[p.first][p.second]) {
                if (i != p.first && j != p.second)
                    return false;
            }
        }

    return true; // 같은 숫자가 없으면 --> 그 숫자로 채울 수 있음.
}

void find(int n) { // n : 이번에 채울 빈칸 번호 (몇 번째? 0 ~ cnt - 1)

    // base case
    if (n == cnt) { // 스도쿠 다 채우면
        is_full = true;

        for (int i = 0; i < 9; i++) { //출력
            for (int j = 0; j < 9; j++)
                cout << sdoqu[i][j] << " ";
            cout << '\n';
        }
        return;
    }

    for (int j = 1; j <= 9; j++) {
        sdoqu[v_empty[n].first][v_empty[n].second] = j; // 하나씩 넣어보면서
        if (check(v_empty[n])) // 가능하면
            find(n + 1); // 그대로 두고 다음 빈칸을 채우기

        if (is_full) return; // 이미 다 채웠을 경우 --> 함수 종료
    }
    sdoqu[v_empty[n].first][v_empty[n].second] = 0; // 값을 채우지 않고 빈칸으로 남기는 경우도 고려해주기.
    return;
}

int main() {
    /*입력 받기*/
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdoqu[i][j];
            if (sdoqu[i][j] == 0) {
                v_empty.push_back({ i, j });
                cnt++;
            }
        }
    }

    /*스도쿠 채우기*/
    find(0);
}
