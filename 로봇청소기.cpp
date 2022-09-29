#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, int r, int c, int d, vector<vector<int>> &board) {
    int answer = 0;
    int nx, ny, nd, check;
    int dx[4] = {-1, 0, 1, 0}; //북, 동, 남, 서 표시
    int dy[4] = {0, 1, 0, -1};

    while(1) {
        if (board[r][c] == 0) {
            answer++; //청소한 구역수 올리기
            board[r][c] = 2; //청소한거 표시
        }
        for (check = 0; check < 4; check++) {
            d = (d+3) % 4;
            nx = r + dx[d];
            ny = c + dy[d];
            if(board[nx][ny] == 0) {r=nx; c=ny; break;} //청소 안한곳이면 이동하고 되돌아가기
        }
        if (check == 4) {
            nd = (d+2)%4;
            nx = r+dx[nd];
            ny = c +dy[nd];
            if (board[nx][ny] ==1) break; //벽일 경우 멈춤, 벽 아니면 이동

            r = nx;
            c = ny;
        }
    }
    return answer;
}

int main(void) {
    int n, m, r, c, d;
    scanf("%d %d", &n, &m);
    vector<vector<int>> board(n, vector<int>(m,0));
    scanf("%d %d %d", &r, &c, &d);
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin>>board[i][j];
    printf("%d", solution(n,m,r,c,d,board));
    return 0;
}