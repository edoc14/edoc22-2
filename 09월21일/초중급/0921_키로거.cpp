#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//해결 포인트 : 두개의 스택으로 !
//백터로 !

//스택을 문자열로 바꿔주는 함수
string stackToString (stack<char> &left , stack<char> &right){
    string ans;

    //왼쪽 스택에서 오른쪽 스택으로 넣어주기. -> 오른쪽 스택은 비밀 번호의 역순으로 문자가 들어가 있음
    while(!left.empty()){
        right.push(left.top());   //왼쪽 스택의 top을 오른쪽 스택에 push
        left.pop();  //그리고 pop으로 정리
    }
    while(!right.empty()){  //오른쪽 스택에 역순으로 문자가 들어가 있음을 고려해서 문자열로 정리해주기
        ans += right.top(); // 다음과 같은 연산이 가능하다는 것을 기억하기
        right.pop();  //pop
    }

    return ans;
}

string find (string input){  //비밀번호 찾는 과정
    stack <char> left;  //커서 기준 왼쪽에 있는 문자들을 stack
    stack <char> right; // 커서 기준 왼쪽에 있는 문자들을 stack (char형임을 주의)

    for(int i=0 ; i<input.length() ; i++){  //입력 받은 문자들 하나씩 탐색
        switch(input[i]){  //스위치문 학습
            case '-' ://삭제
                if(!left.empty()){ //커서 기준 왼쪽에서 하나 지워주기
                    left.pop(); //pop
                }
                break; //break 잊지말것

            case '<' : //왼쪽으로 이동
                if(!left.empty()){  //커서 기준 왼쪾에 있는 문자을 커서 기준 오른쪽으로 바꿔주기
                    right.push(left.top());  //top을 push
                    left.pop();  //pop
                }
                break;

            case '>' :  //오른쪽으로 이동
                if(!right.empty()){  //커서 기준 왼쪾에 있는 문자을 커서 기준 오른쪽으로 바꿔주기
                    left.push(right.top());
                    right.pop();
                }
                break;

            default :
                left.push(input[i]);
        }

    }

    // 얘 위치 주의해!! ㅠㅠ
    string ans = stackToString( left, right);  //스택을 기준으로 문자열로 정리해주기

    return ans;

}

vector<string> solution(int t,  vector<string>& input_list) {  //solustion 함수
    vector <string> ans;
    for(int i=0 ; i< t ; i++){
        ans.push_back(find(input_list[i]));   //find함수로 비밀번호 찾아주기
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    //솔루션 함수 작성을 위해서
    vector<string> input_list(t, " ");
    for(int i=0 ; i<t ; i++){
        cin >> input_list[i];
    }

    auto answer = solution( t, input_list);


    for(int i=0 ; i<t ; i++){ // 이 형태 기억
        cout << answer[i] << '\n';
    }

    return 0;
}