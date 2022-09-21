#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,c;
vector<int> v;

int main() {
    cin >> n >> c;
    for(auto i =0; i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    int start = 0;
    int end = v[n-1];
    int res = 0;
    int temp,cnt;

    while(start <= end) {
        int mid = (start + end)/2;
        temp=0, cnt =1;
        for(auto i=1;i<n;i++) {
            if(v[i]-v[temp]>=mid) {
                temp=i;
                cnt++;
            }
        }

        if(cnt>=c) {
            res = mid;
            start = mid+1;
        }else {
            end = mid-1;
        }
    }
    cout << res;
} 
