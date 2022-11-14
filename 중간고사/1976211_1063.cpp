#include <iostream>
#include <string>
using namespace std;

string king,rock; //현재 위치
string prev_king, prev_rock; //이전 위치
int num;


int main() {
    cin>>king>>rock>>num;
    prev_king=king; prev_rock=rock;

    string mov;
    while (num--){
        cin>>mov;
        if(mov=="R"){
            king[0]+=1;
        }else if(mov=="L"){
            king[0]-=1;
        }else if(mov=="B"){
            king[1]-=1;
        }else if(mov=="T"){
            king[1]+=1;
        }else if(mov=="RT"){
            king[0]+=1;
            king[1]+=1;
        }else if(mov=="LT"){
            king[0]-=1;
            king[1]+=1;
        }else if(mov=="RB"){
            king[0]+=1;
            king[1]-=1;
        }else if(mov=="LB"){
            king[0]-=1;
            king[1]-=1;
        }

        //돌과 겹치면 돌 옮기기
        if(rock==king){
            if(mov=="R"){
                rock[0]+=1;
            }else if(mov=="L"){
                rock[0]-=1;
            }else if(mov=="B"){
                rock[1]-=1;
            }else if(mov=="T"){
                rock[1]+=1;
            }else if(mov=="RT"){
                rock[0]+=1;
                rock[1]+=1;
            }else if(mov=="LT"){
                rock[0]-=1;
                rock[1]+=1;
            }else if(mov=="RB"){
                rock[0]+=1;
                rock[1]-=1;
            }else if(mov=="LB"){
                rock[0]-=1;
                rock[1]-=1;
            }
            //돌이 체스판으로 나갈 경우 원상 복귀
            if(rock[0]<'A'||rock[0]>'H'||rock[1]<'1'||rock[1]>'8'){
                king=prev_king; rock=prev_rock;
                continue;
            }

        }

        //킹이 체스판으로 나갈 경우 원상 복귀
        if(king[0]<'A'||king[0]>'H'||king[1]<'1'||king[1]>'8'){
            king=prev_king; rock=prev_rock;
            continue;
        }
        prev_king=king; prev_rock=rock;
    }

    cout<<king<<'\n'<<rock;


    return 0;
}
