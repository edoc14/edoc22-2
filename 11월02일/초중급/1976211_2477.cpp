#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K;

int dir[6];
int len[6];

int main() {
    cin>>K;
    //가장 긴 가로, 세로 변
    int maxX=0,maxY=0;
    int maxX_idx=-1,maxY_idx=-1;

    for (int i = 0; i < 6; ++i) {
        cin>>dir[i]>>len[i];
        if(dir[i]<3){ //가로 변
            if(maxX<len[i]){
                maxX=len[i];
                maxX_idx=i;
            }
        } else { //세로 변
            if(maxY<len[i]){
                maxY=len[i];
                maxY_idx=i;
            }
        }
    }
    //큰 사각형
    int bigSqr=maxX*maxY;
    //작은 사각형: 항상 큰 변의 인덱스+3에 위치
    int smallSqr=len[(maxX_idx+3)%6]*len[(maxY_idx+3)%6];

    int ans=bigSqr-smallSqr;
    cout<<ans*K;

    return 0;
}
