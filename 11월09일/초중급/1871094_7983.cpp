#include <iostream>
#include <queue>

using namespace std;

struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; // 제출일 기준 내림차순
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        pq.push({start, end});
    }
    int daysLeft = pq.top().second - pq.top().first;
    pq.pop();
    while (!pq.empty()) {
        int d = pq.top().first; // d일이 걸린다
        int t = pq.top().second; // t일까지 끝내야한다
        pq.pop();
        if (daysLeft >= t) daysLeft = t - d;
        else daysLeft = daysLeft - d;
    }
    cout << daysLeft;

    return 0;
}