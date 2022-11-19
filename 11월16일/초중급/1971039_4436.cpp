#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    while (true) {
        long long n; //반드시 long long으로 해야함 (아니면 19번째줄 연산시 형변환 필요)
        cin >> n;
        if (cin.eof() == true) {
            break;
        }

        int i = 1;
        set<int> s;
        while (s.size() < 10) {
            long long num = n * i; //반드시 long long으로 해야함
            while (num != 0) {
                s.insert(num % 10);
                num /= 10;
            }
            i++;
        }
        cout << i - 1 << "\n";
    }
}