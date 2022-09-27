#include <iostream>
#include <deque>
using namespace std;
deque<char> getPW(string str) {
    deque<char> left, right;
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='>') {
            if(!right.empty()){
                left.push_back(right.front());
                right.pop_front();
            }
        } else if(str[i]=='<') {
            if(!left.empty()) {
                right.push_front(left.back());
                left.pop_back();
            }
        } else if(str[i]=='-') {
            if(!left.empty()) {
                left.pop_back();
            }
        } else {
            left.push_back(str[i]);
        }
    }
    while(!right.empty()) {
        left.push_back(right.front());
        right.pop_front();
    }

    return left;
}
int main() {
    int n; cin>>n;
    while(n--) {
        string input;
        cin>>input;
        deque<char> pw=getPW(input);
        while(!pw.empty()) {
            cout<<pw.front();
            pw.pop_front();
        }
        cout<<"\n";
    }
    return 0;
}