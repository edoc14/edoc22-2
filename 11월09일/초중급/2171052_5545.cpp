#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,A,B,C;
    int D[100];
    int cal=0;
    int mon=0;
    
    cin>> n;
    cin>>A>>B;
    cin>>C;
    for(int i=0;i<n;i++){
        cin>>D[i];
    }
    sort(D,D+n);
    cal+=C;
    mon+=A;
    
    for(int i=n-1;i>=0;i--){
        if(((double)cal/mon)<(double)((cal+D[i])/(mon+B))){ cal+=D[i]; mon+=B;}
    }
    cout<<cal/mon;

    return 0;
}
