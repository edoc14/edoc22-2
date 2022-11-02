#include <iostream>
#include <vector>
using namespace std;
int count[5];
vector <pair<int,int>> v;

int main()
{
    int n,a,b;
    cin>>n;
    
    int minus=0;;
    int ans=1;
    
    for(int i=0;i<6;i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        count[a]++;
    }
    for(int i=0;i<6;i++){
        if(count[v[i].first]==1){
            ans*=v[i].second;
        }
    }
    for(int i=0;i<6;i++){
        v.push_back(v[i]);
    }
    int s=0;
    for(int i=0;i<12;i++){
        if(count[v[i].first]==2){
            s++;
            if(s==4){
                minus=v[i-1].second;
                minus*=v[i-2].second;
            }
        }
        else{
            s=0;
        }
    }
    
    cout<<(ans-minus)*n;
    return 0;
}
