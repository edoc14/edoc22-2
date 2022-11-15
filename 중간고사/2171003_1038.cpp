#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
queue<ll> q;
int cnt = 0;
int n;
void backtracking(ll &result) {
    cnt++;
    ll cur = q.front();
    q.pop();
    if(cnt==n) {
        result = cur;
        return;
    }
    ll next = 10 * cur;
    for (int i = 0; i < cur % 10; i++) {
        q.push(next);
        next++;
    }
    backtracking(result);
}
int main() {
    cin >> n;
    for (int i = 1; i < 10; i++) {
        q.push(i);
    }
    ll result=0;
    if(n==0) result = 0;
    else if(n>1022) result = -1;
    else backtracking(result);
    cout << result<<endl;
    return 0;
}