#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    sort(d.begin(), d.end()); //열량 정렬

    int cal = c;
    int money = a;
    int best = c / a;

    for (int i = n - 1; i >= 0; i--) {
        cal += d[i];
        money += b;
        if (best < cal / money) {
            best = cal / money;
        }
    }
    cout << best;
}