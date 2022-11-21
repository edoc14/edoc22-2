#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> condo(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        condo[i] = make_pair(a, b);
    }

    // sort(condo.begin(), condo.end());

    int count = 0;
    for (int i = 0; i < n; i++) { //기준
        int check = true;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;

            if (condo[j].first < condo[i].first && condo[i].second >= condo[j].second) {
                check = false;
                break;
            }
            if (condo[j].second < condo[i].second && condo[j].first <= condo[i].first) {
                check = false;
                break;
            }
        }
        if (check)
            count++;
    }
    cout << count;
}