#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//복도의 번호를 0~199라 할 때, 각 복도는 한번에 한번씩 쓸 수 있다.
//따라서 이동과정에서 복도를 몇번 이용해야 하는지 카운트하여 최댓값을 구하면 된다.
int main() {
    int tc, n, s, t;

    cin >> tc;
    while (tc--) {
        vector<int> DPl(200, 0);
        cin >> n;
        while (n--) {
            cin >> s >> t;
            if (s > t) {
                swap(s, t);
            }
            for (int i = (s - 1) / 2; i <= (t - 1) / 2; i++) {
                DPl[i]++;
            }
        }
        cout << *max_element(DPl.begin(), DPl.end()) * 10 << '\n';
        
    }
    return 0;
}