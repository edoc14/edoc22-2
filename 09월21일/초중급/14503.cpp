#include <iostream>
#include <vector>
using namespace std;
vector<int> dx={-1, 0, 1, 0};
vector<int> dy={0, 1, 0, -1};   //0:북, 1:동, 2:남, 3:서

int clean(vector<vector<int>> &area, int n, int m, int r, int c, int d) {
    area[r][c]=-1;  //첫번째 위치 청소

    int x=r, y=c, cnt=1;
    int nx, ny, nd;
    bool flag;  //네 방향 중 청소한 곳 유무 저장
    while(1) {
        flag=false;
        for(int i=1; i<=4; i++) { //왼쪽 방향으로 4번 돌기
            nd=(d-i+4)%4;
            nx=x+dx[nd], ny=y+dy[nd];
            if(0<=nx && nx<n && 0<=ny && ny<m && area[nx][ny]==0) { //청소할 공간이 있으면
                x=nx; y=ny; d=nd; //그 방향으로 회전하고 전진하기
                area[x][y]=-1;  //현재 위치 청소하기
                cnt++;  //청소한 칸 1 증가
                flag=true;
                break;
            }
        }
        if(flag) { //네 방향 중 한 곳을 청소한 경우
            continue;   //1번으로 돌아가기
        }

        nx=x-dx[d]; ny=y-dy[d]; //뒤쪽 방향
        if(0<=nx && nx<n && 0<=ny && ny<m && area[nx][ny]!=1) {
            x=nx; y=ny; //바라보는 방향 유지한 채 한 칸 후진
            area[x][y]=-1;  //현재 위치 청소하기
            continue;   //2번으로 돌아가기
        } 
        break;
    }
    return cnt;
}
int main() {
    int n, m; cin>>n>>m;
    int r, c, d; cin>>r>>c>>d;
    vector<vector<int>> area(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>area[i][j];
        }
    }
    cout<<clean(area, n, m, r, c, d);
    return 0;
}