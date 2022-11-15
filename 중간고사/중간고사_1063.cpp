#include <iostream>
#include <algorithm>

using namespace std;

int n, kx, ky, sx, sy;
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};

bool check(int idx) {
    int nkx = kx + dx[idx];
    int nky = ky + dy[idx];
    int nsx = sx;
    int nsy = sy;

    if (nkx < 1 || nkx > 8 || nky < 1 || nky > 8) {
        return false;
    }
    if (nkx == nsx && nky == nsy) {
        nsx += dx[idx];
        nsy += dy[idx];
        if (nsx < 1 || nsx > 8 || nsy < 1 || nsy > 8) {
            return false;
        }
        kx = nkx;
        ky = nky;
        sx = nsx;
        sy = nsy;
        return true;
    }
}

int main() {
    string k_loc, s_loc, ans = "";
    cin >> k_loc >> s_loc >> n;

    kx = k_loc[0] - 'A' + 1;
    ky = k_loc[1] - '1' + 1;
    sx = s_loc[0] - 'A' + 1;
    sy = s_loc[1] - '1' + 1;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "R") {
            if (!check(0)) continue;

        } else if (op == "L") {
            if (!check(1))continue;
        } else if (op == "B") {
            if (!check(2))continue;
        } else if (op == "T") {
            if (!check(3))continue;
        } else if (op == "RT") {
            if (!check(4))continue;
        } else if (op == "LT") {
            if (!check(5))continue;
        } else if (op == "RB") {
            if (!check(6))continue;
        } else if (op == "LB") {
            if (!check(7))continue;
        }
    }

    cout << (char) ('A' - 1 + kx) << ky << "\n";
    cout << (char) ('A' - 1 + sx) << sy << "\n";

    return 0;
}