#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> doll(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> doll[i];
    }

    int left = doll[1], right = doll[2];
    for (int i = 3; i <= n; i++) {
        if (left == right) {
            left += doll[i];
        } else {
            if (left < right) {
                left += doll[i];
            } else {
                right += doll[i];
            }
        }
    }

    int count = 0, remain = 0;

    if (left != right) {
        remain = (left - right) > 0 ? left - right : right - left;
        count += remain / 100;
        remain %= 100;
        count += remain / 50;
        remain %= 50;
        count += remain / 20;
        remain %= 20;
        count += remain / 10;
        remain %= 10;
        count += remain / 5;
        remain %= 5;
        count += remain / 2;
        remain %= 2;
        count += remain;
    }

    cout << count;
}