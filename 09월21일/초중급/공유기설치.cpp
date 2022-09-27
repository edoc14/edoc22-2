#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// binary search
//we have to consider distance rather than index

int main() {

    int N,C;
    vector<int> v; //define a vector v
    int start = 0; //starting point
    int end = v[N-1]; //max distance
    int res = 0; //result
    int temp, cnt; //temporary and count variable

    cin >> N >> C; //input

    //enter all of cooridinates inside vector
    for(auto i = 0 ; i < N ;i++) {
        int x; 
        cin >> x;
        v.push_back(x);
    }

    // sort the coordinates of houses
    sort(v.begin(),v.end());

    //binary search from the distance --> if distance goes away, update the value
    while(start <= end) {
        int mid = (start + end)/2;
        temp=0, cnt =1;
        for(auto i = 1 ; i < N ; i++) {
            if(v[i] - v[temp] >= mid) { 
                temp = i;
                cnt++;
            }
        }
        if(cnt >= C) {
            res = mid;
            start = mid+1;
        }else {
            end = mid-1;
        }
    }
    //print the result by binary search
    cout << res;
} 
