#include <iostream>
using namespace std;
typedef long long int ll;
ll A,B,C;
int main() {
    cin>>A>>B>>C;

    //A+B*n와 C*n가 양수 해가 없을 때 손익분기점 없음
    if(C<=B) { cout << -1; return 0; }

    //교점의 바로 다음 정수
    ll n=A/(C-B)+1;

    cout<<n;
    return 0;
}
