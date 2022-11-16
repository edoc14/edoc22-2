#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int base;
    cin >> base;
    vector<int> toppings = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> toppings[i];
    }
    sort(toppings.begin(), toppings.end(), greater<int>());
    int ans = -1;
    for (int i = 0; i <= n; i++) {
        int cost = base;
        for (int j = 0; j < i; j++) {
            cost += toppings[j];
        }
        ans = max(ans, cost / (a + b * i));
    }
    cout << ans;

    return 0;
}