#include <iostream>

using namespace std;

/*
 * [1712 손익분기점]
 * 노트북 판매 대수와 상관 없는 고정 비용 : A
 * 한대당 생산 비용 : B
 * 노트북 가격 : C
 *
 * 손익분기점 : C*cnt > A+ B * cnt
 */

int cnt(int a, int b, int c) {
    int ans = 1;
    if (b >= c) return -1;
    int gap = c - b;
    ans = a / gap + 1;

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << cnt(a, b, c);

    return 0;
}