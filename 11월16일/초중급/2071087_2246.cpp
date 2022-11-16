#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int N,D,C;
    cin >> N; 
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        cin >> D>>C; 
        v.push_back({ D,C });
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 1; 
    int nowD = v[0].first, nowC = v[0].second;
    
   //1. X보다 바닷가에 더 가까운 콘도들은 모두 X보다 숙박비가 더 비싸다.
   //2. X보다 숙박비가 더 싼 콘도들은 모두 X보다 바닷가에서 더 멀다. 
    for (int i =  1; i < N; i++) {
        if (v[i].first > nowD && v[i].second < nowC) {
            ++cnt;
            nowD = v[i].first;
            nowC = v[i].second;
        }
    }
    cout << cnt;
    return 0;
}