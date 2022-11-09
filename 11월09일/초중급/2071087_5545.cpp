#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, A, B, C,price,toCal,cal;
    vector<int> v;
    cin>>N;
    cin>>A>>B;
    cin>>C;
    for (int i = 0; i < N; i++) {
        cin>>toCal;
        v.push_back(toCal);
    }
    //토핑 열량 v[i] 내림차순으로 정렬
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<N;i++){

    }
    cout<<cal/price;

}