#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct hw{
    int d;
    int t;
    int s;
};
hw HW[1000000];

bool cmp(hw a, hw b)
{
    return a.t<b.t;
}

int main()
{
    int n;
    cin>>n;
    
    
    for(int i=0;i<n;i++){
        cin>>HW[i].d>>HW[i].t;
        HW[i].s=HW[i].t-HW[i].d;
    }
    sort (HW,HW+n,cmp);
    for(int i=n-2;i>=0;i--){
        if(HW[i+1].s<HW[i].t){HW[i].s=HW[i].s-(HW[i].t-HW[i+1].s);}
    }
    cout<<HW[0].s;
    return 0;
}
