#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int countDP(vector<pair<int, int>> &arr) {
    vector<int> dp(200, 0); //복도

    for (int i = 0; i < arr.size(); i++) {
        // (1,2), (3,4) ,(5,6) 이런식으로 복도를 공유
        for (int j = (arr[i].first - 1) / 2; j <= (arr[i].second - 1) / 2; j++)
            dp[j] += 10; // 10분
    }

    return *max_element(dp.begin(), dp.end()); // dp 배열 중 가장 큰 값 출력
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        vector<pair<int, int>> arr(n, {0, 0}); //방

        //입력
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;

            if (arr[i].first > arr[i].second)
                swap(arr[i].first, arr[i].second); //무조건 뒤에께 더 큰 수가 되도록
        }

        int result = countDP(arr);
        cout << result << '\n';
    }
}