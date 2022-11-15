#include <iostream>
#include <math.h>

using namespace std;

int n;
int num[11][10] = {0};
long long ans = -1;

void dfs(int start, int digit, long long now) {
    if (digit == 0) {
        return;
    }

    if (digit == 1) {
        now += (n - 1);
        ans = now;
        return;
    } else {
        for (int i = 0; i <= start; i++) {
            if (!num[digit][i])
                continue;

            n -= num[digit][i];
            if (n <= 0) {
                n += num[digit][i];
                now += i * pow(10, digit - 1);
                dfs(i - 1, digit - 1, now);
                break;
            }
        }
    }
}

int main() {

    for (int i = 0; i < 10; i++) {
        num[1][i] = 1;
    }

    for (int i = 2; i < 11; i++) {
        for (int j = i - 1; j < 10; j++) {
            if (i == j + 1)
                num[i][j] = 1;
            else {
                for (int k = 0; k < j; k++) {
                    num[i][j] += num[i - 1][k];
                }
            }
        }
    }

    cin >> n;
    if (n == 0) {
        cout << "0" << "\n";
        return 0;
    }
    if (n > 1022) {
        cout << "-1" << "\n";
        return 0;
    } else if (n == 1022) {
        cout << "9876543210" << "\n";
        return 0;
    }

    int start, digit;
    bool flag = false;
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 10; j++) {
            if (!num[i][j])
                continue;

            n -= num[i][j];
            if (n <= 0) {
                flag = true;
                ans = (long long) j * pow(10, i - 1);
                n += num[i][j];
                dfs(j - 1, i - 1, ans);
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}