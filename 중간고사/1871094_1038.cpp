#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n <= 10) {
        cout << n;
        return 0;
    }
    queue<long long> que;
    for (int i = 0; i < 10; i++) {
        que.push(i);
    }
    int cnt = 9;
    while (cnt < n && !que.empty()) {
        long long num = que.front();
        que.pop();
        if (num == 9876543210) { // 9876543210 이후에는 감소하는 수가 존재하지 않는다.
            cout << -1;
            return 0;
        }
        long long mx = num % 10; // 마지막 자리수
        long long nextNum = num * 10;
        for (int j = 0; j < mx; j++) { // 마지막 자리수보다 작은 수 뒤에 추가
            que.push(nextNum++);
            cnt++;
            if (cnt == n) break;
        }
    }
    cout << que.back();
    return 0;
}