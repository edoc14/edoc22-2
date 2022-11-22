#include <iostream>
#include <vector>
using namespace std;
int main() {
    int k;
    cin >> k;
    vector<int> cnt(5, 0);
    vector<vector<int>> length(6, vector<int>(2));
    for (int i = 0; i<6; i++) {
        int dir, len;
        cin >> dir >> len;
        cnt[dir]++;
        length[i][0] = dir;
        length[i][1] = len;
    }

    int large_area = 1;
    int small_area = 1;

    for (int i = 0; i < 6; i++) {
        if(cnt[length[i][0]]==1) {
            large_area *= length[i][1];
        } else {
            int next = (i + 2) % 6;
            if(length[i][0]==length[next][0]) {
                small_area *= length[(i + 1) % 6][1];
            }
        }
    }

    cout << (large_area - small_area) * k;
    return 0;
}