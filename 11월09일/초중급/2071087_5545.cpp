#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, A, B, C,price,toCal; //토핑 개수, 도우 가격, 토핑 가격, 도우 열량
    vector<int> v; //토핑 열량 벡터
    cin>>N;
    cin>>A>>B;
    cin>>C;
    for (int i = 0; i < N; i++) {
        cin>>toCal;
        v.push_back(toCal);
    }
    //토핑 열량 v[i] 내림차순으로 정렬
    sort(v.begin(),v.end(),greater<int>());
    int doughCal = C/A; //1원 당 도우 열량
    int bestCal = doughCal; //최고의 피자의 1원당 열량(토핑 선택 안 함)
    //토핑 추가했을 때 최고의 피자가 되는 경우
    int totalPrice = A; //총 가격
    int totalCal = C; //총 열량
    for(int i=0;i<N;i++){
        totalPrice += B;
        totalCal += v[i];
        if(bestCal<totalCal/totalPrice){
            bestCal = totalCal/totalPrice;
        }
    }
    cout<<bestCal;
}