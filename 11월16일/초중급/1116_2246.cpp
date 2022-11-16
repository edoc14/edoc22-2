#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<pair<int, int>> &condo_loc,  vector<pair<int, int>> &condo_cost){
    int cnt=0;

    for(int i=0; i<n ; i++){
        int x = condo_loc[i].second;
        int x_loc = condo_loc[i].first;
        int x_cost =
    }

    return cnt;
}

int main(){
    //입력
    int n;
    cin >> n;
    vector<pair<int, int>> condo_loc; //거리
    vector<pair<int, int>> condo_cost; //가격
    for(int i=0 ; i<n ; i++){
        condo_loc[i].second = i;
        condo_cost[i].second = i;
        cin >> condo_loc[i].first>> condo_cost[i].first;
    }

    sort(condo_loc.begin(), condo_loc.end());
    sort(condo_cost.begin(), condo_cost.end());
    cout << solution(n , condo_loc, condo_cost);

    return 0;
}