#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 10) {
        cout << n;
        return 0;
    }

    queue<long long> q;
    for (int i = 1; i <= 9; i++)
        q.push(i);
    int cnt = 9; //큐에 9까지 넣었으니까.

    while (cnt < n) {
        long long num = q.front();
        q.pop();

        if (num == 9876543210) { //이 뒤로는 감소하는 수 존재 X
            cout << -1;
            return 0;
        }
        int back = num % 10;
        for (int i = 0; i < back; i++) {
            q.push(num * 10 + i);
            cnt++;
            if (cnt == n)
                break;
        }
    }

    cout << q.back();
}