#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> dp(200, 0);
        int num;
        cin >> num;
        int start, last;
        while (num--) {
            cin >> start >> last;
            if (start > last) swap(start, last);
            start = (start - 1) / 2;
            last = (last - 1) / 2;
            for (int i = start; i <= last; ++i) dp[i] += 10;
        }
        int result = 0;
        for (int i = 0; i < 200; ++i) result = max(result, dp[i]);

        cout << result << '\n';

    }

    return 0;
}