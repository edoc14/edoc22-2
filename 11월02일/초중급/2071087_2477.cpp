#include <iostream>
#include <vector>
using namespace std;

int k;  //참외 개수
pair<int,int> line[6]; //밭 6변
int width = 1;
int result = 0; 

void input(){
    cin>>k; //참외 개수 입력
    for (int i = 0; i < 6; i++) {
        //참외밭 6변 입력
        cin>>line[i].first>>line[i].second;
    }
}

int Solution(){
    for (int i = 0; i < 6;i++) {
        //현재 변과 다음 변을 곱한다.
        int cur = line[i].second*line[(i+1)%6].second;
        if (width==1||cur>width){
            //곱한 값 중 가장 큰 값을 저장
            width=cur;
            //(i+3)%6번째 변과 (i+4)%6번째 변을 곱해 전체 넓이에서 빼주고 참외 개수 곱한다.
            result=(width-line[(i+3)%6].second*line[(i+4)%6].second)*k;
        }
    }
    //결과 반환
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input(); //입력
    cout<<Solution()<<endl; //출력
    return 0; //종료
}
