#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int> D(N);
    vector<int> C(N);
    int d,c;
    for(int i=0;i<N;i++){
        cin>>d>>c;
        D.push_back(d);
        C.push_back(c);
    }
    cout<<0;
    return 0;
}
