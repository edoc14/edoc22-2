#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    if (B >= C) {
        cout << -1;
        return 0;
    }
    cout << A / (C - B) + 1;
    return 0;
}