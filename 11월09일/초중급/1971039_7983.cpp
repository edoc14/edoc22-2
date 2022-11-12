#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) { //정렬함수
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> assignment(n);

    for (int i = 0; i < n; i++) {
        cin >> assignment[i].first >> assignment[i].second;
    }

    sort(assignment.begin(), assignment.end(), compare); //정렬

    int day = assignment[0].second;
    for (int i = 0; i < n; i++) {
        if (day > assignment[i].second) {
            day = assignment[i].second;
        }
        day -= assignment[i].first;
    }

    cout << day;
}