#include <iostream>
#include <queue>

using namespace std;

struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else return a.first < b.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        pq.push({end, end - start});
    }
    int daysLeft;
    while (!pq.empty()) {
        daysLeft = pq.top().second;
        pq.pop();
        while (!pq.empty()) {
            if (pq.top().first <= daysLeft) {
                break;
            }
            int gap = pq.top().first - daysLeft;
            auto tmp = pq.top();
            pq.pop();
            pair<int, int> newPair = {tmp.first - gap, tmp.second - gap};
            pq.push(newPair);
        }
    }
    cout << daysLeft;

    return 0;
}