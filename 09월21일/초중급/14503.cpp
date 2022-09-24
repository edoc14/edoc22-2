#include <iostream>
using namespace std;

int N,M,r,c,dir,ans=0;

//현재 방향으로 한 칸 전진 0:북쪽 1:동쪽 2:남쪽 3: 서쪽
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

//현재 방향에서 한 칸 후진 0:북쪽 1:동쪽 2:남쪽 3: 서쪽
int bx[4]={1,0,-1,0};
int by[4]={0,-1,0,1};

int map[55][55];

int main() {
    cin>>N>>M;
    cin>>r>>c>>dir;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>map[i][j];
        }
    }

    while (true){
        //현재 위치가 벽이 아니고 청소되지 않음
        if(map[r][c]==0){
            map[r][c]=2; //청소 완료
            ans++;
        }

        bool nxt = false; //다음 위치 찾았는지 표시
        int nxtDir,nxtX,nxtY; //다음 위치 정보 및 방향

        //사방이 막혀있거나 청소되어 있을 때까지 회전
        for (int i = 1; i < 5; ++i) {
            //왼쪽으로 i번 회전
            if(dir-i<0){
                nxtDir=dir-i+4;
            } else {
                nxtDir=dir-i;
            }

            //한 칸 전진
            nxtX=r+dx[nxtDir];
            nxtY=c+dy[nxtDir];

            //다음 위치가 범위 안에 있고, 청소되지 않았을 때 즉 다음으로 청소할 위치를 찾았을 때
            if(nxtY>=0 && nxtX>=0 && nxtY<M && nxtX<N){
                if(map[nxtX][nxtY]==0){
                    nxt= true;
                    break;
                }
            }

        }

        //청소할 다음 위치를 찾았을 때
        if(nxt){
            //좌표 이동
            r=nxtX;
            c=nxtY;
            dir=nxtDir;
        } else {
            //뒤가 벽인지 확인
            int backX=r+bx[dir];
            int backY=c+by[dir];
            if(map[backX][backY]==1){ //더이상 진행 불가
                break;
            } else { //한 칸 후진
                r=backX;
                c=backY;
            }
        }
    }
    cout<<ans;

    return 0;
}
