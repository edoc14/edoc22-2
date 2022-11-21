#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b, a;
    cin >> n >> b >> a;
    vector<int> gift(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> gift[i];
    }

    sort(gift.begin(), gift.end());
    int count = 0;
    for (int i = 1; i <= n; i++) { //선물 개수
        int ssum = 0;
        for (int j = 1; j <= i; j++) {
            if (j > i - a) {
                ssum += (gift[j] / 2);
            } else {
                ssum += gift[j];
            }
        }

        if (ssum <= b) {
            count = i;
        }
    }

    cout << count;
}