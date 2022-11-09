#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, a, b;
    cin >> k;
    int maxx = 0, maxy = 0;

    vector<pair<int, int>> arr;
    for (int i = 0; i < 6; i++) {
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
        if (a >= 3) { //가로
            maxx = max(maxx, b);
        } else {
            maxy = max(maxy, b);
        }
    }
    arr.push_back(arr[0]);

    int small = 0;
    for (int i = 0; i < 7; i++) {
        int f = arr[i].first;
        int bb = arr[i + 1].first;

        if ((f == 1 && bb == 3) || (f == 4 && bb == 1) || (f == 2 && bb == 4) || (f == 3 && bb == 2)) {
            small = arr[i].second * arr[i + 1].second;
        } else {
            continue;
        }

        cout << (maxx * maxy - small) * k;
        return 0;
    }
}