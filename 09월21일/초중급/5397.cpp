#include <iostream>
#include <list>
#include <string>
using namespace std;

int N; //test case

int main() {
    cin>>N;

    while(N--){
        string str; //키로그
        list<char> pw; //입력된 비밀번호
        auto cursor = pw.end(); //현재 커서 위치

        cin>>str;

        for (auto c : str) {
            if(c=='-') { //커서 왼쪽 삭제
                if (cursor!=pw.begin()) {
                    cursor = pw.erase(--cursor);
                }
            } else if(c=='<'){ //cursor 좌측 이동
                if(cursor!=pw.begin()) cursor--;

            } else if(c=='>'){//cursor 우측 이동
                if(cursor!=pw.end()) cursor++;

            } else { //커서 우측 삽입
                pw.insert(cursor,c);
            }

        }

        //비밀번호 출력
        for (auto c : pw) {
            cout<<c;
        }
        cout<<'\n';
    }
    return 0;
}
