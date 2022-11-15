#include <iostream>

using namespace std;

long long d[1000001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        d[i] = i;
    }
    int num = 10;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (d[i] % 10); j++) {
            d[num++] = d[i] * 10 + j;
        }
    }
    if (n > 1022)
        cout << -1;
    else
        cout << d[n];
    return 0;
}
