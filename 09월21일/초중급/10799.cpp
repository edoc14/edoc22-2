#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    stack<char> st;
    int answer = 0;

    for (int i = 0; i < str.length(); i++) {
        //여는 괄호이면 stack에 push 한다.
        if (str[i] == '(') {
            st.push('(');
        } else { //닫는 괄호일 때
            st.pop();
            if (str[i - 1] == '(') { // 레이저일 때
                answer += st.size();
            } else { // 쇠막대기의 끝일 때
                answer += 1;
            }
        }
    }
    cout << answer;
}