#include <iostream>

using namespace std;


int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int i;
    int n=-a;
    int A=c-b;
    if(A<=0) cout<<-1;
    else{
        cout<<a/A+1;
        
    }
    
    return 0;
}
