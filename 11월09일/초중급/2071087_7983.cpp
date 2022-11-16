#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> arr;

//제출일을 기준으로 내림차순으로 정렬한다.
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a, b });
    }
    //내림차순 정렬
    sort(arr.begin(), arr.end(), cmp);

    //now : 제출일 - 과제하는 데 걸리는 일 = 제출일에 과제를 끝내기 위해 과제를 시작해야 하는 날
    int now = arr[0].second - arr[0].first;
    for (int i = 1; i < n; i++) {
        int d = arr[i].first, t = arr[i].second;
        //now보다 다음 과제의 제출일이 작거나 같으면 영향 X, 처음처럼 now 갱신
        if (now >= t) {
            now = t - d;
        }
        //아닌 경우 now에서 과제하는 데 걸리는 일만큼 빼서 갱신
        else {
            now = now - d;
        }
    }
    //출력
    cout << now;

    return 0;
}