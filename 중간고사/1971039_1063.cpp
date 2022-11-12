#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int kx, ky, rx, ry, n;
vector<string> arr;

void input() {
    char tmp1, tmp2;
    cin >> tmp1 >> ky >> tmp2 >> ry >> n;
    kx = tmp1 - 'A' + 1;
    rx = tmp2 - 'A' + 1;

    arr.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void R() { //한 칸 오른쪽으로
    if (kx + 1 <= 8) {
        kx++;                       //이동
        if (kx == rx && ky == ry) { //겹치면
            if (rx + 1 <= 8) {
                rx++;
            } else {
                kx--; //원위치
            }
        }
    }
}

void L() { //한 칸 왼쪽으로
    if (kx - 1 >= 1) {
        kx--;                       //이동
        if (kx == rx && ky == ry) { //겹치면
            if (rx - 1 >= 1) {
                rx--;
            } else {
                kx++; //원위치
            }
        }
    }
}

void T() { //한 칸 위로
    if (ky + 1 <= 8) {
        ky++;                       //이동
        if (kx == rx && ky == ry) { //겹치면
            if (ry + 1 <= 8) {
                ry++;
            } else {
                ky--; //원위치
            }
        }
    }
}

void B() { //한 칸 아래으로
    if (ky - 1 >= 1) {
        ky--;                       //이동
        if (kx == rx && ky == ry) { //겹치면
            if (ry - 1 >= 1) {
                ry--;
            } else {
                ky++; //원위치
            }
        }
    }
}

void RT() { //오른쪽 위
    if (ky + 1 <= 8 && kx + 1 <= 8) {
        ky++;
        kx++;                       //이동
        if (kx == rx && ky == ry) { //겹치면
            if (ry + 1 <= 8 && rx + 1 <= 8) {
                ry++;
                rx++;
            } else {
                ky--;
                kx--; //원위치
            }
        }
    }
}

void LT() { //왼쪽 위
    if (ky + 1 <= 8 && kx - 1 >= 1) {
        ky++;
        kx--;                       //이동
        if (kx == rx && ky == ry) { //겹치면
            if (ry + 1 <= 8 && rx - 1 >= 1) {
                ry++;
                rx--;
            } else {
                ky--;
                kx++; //원위치
            }
        }
    }
}

void RB() { //오른쪽  아래
    if (ky - 1 >= 1 && kx + 1 <= 8) {
        ky--;
        kx++;                       //이동
        if (kx == rx && ky == ry) { //겹치면
            if (ry - 1 >= 1 && rx + 1 <= 8) {
                ry--;
                rx++;
            } else {
                ky++;
                kx--; //원위치
            }
        }
    }
}

void LB() { //왼쪽 아래
    if (ky - 1 >= 1 && kx - 1 >= 1) {
        ky--;
        kx--;                       //이동
        if (kx == rx && ky == ry) { //겹치면
            if (ry - 1 >= 1 && rx - 1 >= 1) {
                ry--;
                rx--;
            } else {
                ky++;
                kx++; //원위치
            }
        }
    }
}

void move(int i) {
    string order = arr[i];

    if (order == "L")
        L();
    else if (order == "R")
        R();
    else if (order == "T")
        T();
    else if (order == "B")
        B();
    else if (order == "RT")
        RT();
    else if (order == "RB")
        RB();
    else if (order == "LT")
        LT();
    else if (order == "LB")
        LB();
}

void output() {
    cout << (char)(kx - 1 + 'A') << ky << '\n';
    cout << (char)(rx - 1 + 'A') << ry << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    for (int i = 0; i < n; i++) {
        move(i);
    }
    output();
}