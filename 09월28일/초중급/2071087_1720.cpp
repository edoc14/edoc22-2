#include <iostream>

using namespace std;

int a[31];

int main(){
    int n;
    cin>>n;
    a[0] = 1;
    a[1] = 1;
    a[2] = 3;
    for (int i = 3; i <= n; i++) {
        a[i] = a[i-1] + a[i-2]*2;
    }
    if (n%2){
        cout<<(a[n]+a[n/2])/2;
    }
    else{
        cout<<(a[n]+a[n/2]+a[n/2-1]*2)/2;
    }
    return 0;
}