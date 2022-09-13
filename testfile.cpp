#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T,n;
    cin>>T;
    for(int i=0;i<T;i++){
        vector<int> v;
        for(int j=0;j<5;j++){
            cin>>n;
            v.push_back(n);
        }
        sort(v.begin(),v.end());
        if(v[1]+4<=v[3]){ cout<<"KIN\n"; }
        else {
            int m=v[1]+v[2]+v[3];
            cout<<m<<'\n';
        }
    }

    return 0;
}