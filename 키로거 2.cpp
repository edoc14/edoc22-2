#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string stackplus(stack<char> &left, stack<char> &right) {
    //문자열 두개 하나로 합침
    string password;
    //왼쪽 스택 top부터 오른쪽 스택에 삽입
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        password += right.top();
        right.pop();
    }
    return password;
}

string findpassword(string log) {
    stack<char> left; 
    stack<char> right;
    //커서 이전/이후 내용 저장

    for (int i=0; i < log.length(); i++) {
        switch (log[i]) {
            //글자 삭제
            case '-':
                if (!left.empty()) {
                    left.pop();
                }
                break;
            //커서 이동
            case '<':
                if (!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
                break;
            case '>':
                if(!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
                break;
            default:
                left.push(log[i]);
        }
    }

    string password = stackplus(left, right);
    return password;
}

vector<string> solution(int t, vector<string> &log_list) {
    vector<string> answer;
    for (int i=0; i < t; i ++) {
        answer.push_back(findpassword(log_list[i]));
    }
    return answer;
}

int main() {
    int t;
    cin>> t;
    vector<string> log_list(t, "");

    for (int i = 0; i < t; i++) {
        cin >> log_list[i];
    }
    auto answer = solution(t, log_list);
    for (int i = 0; i < t; i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}