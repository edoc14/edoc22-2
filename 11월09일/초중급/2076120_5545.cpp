/*
최고의 피자 (백준 5545)
피자 열량을 구해야함..
그러면 총 열량/가격이 가장 적은 것을 골라야한다.
가격이 똑같고 열랑이 다름
열량 총합 /A+B*k 이거의 최댓값을 구해야함..
도우는 디폴트. 총합 하나씩 합 두개씩 합 세개씩 합 이런식으로 다 해야함..
*/
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int N;   // 토핑 종류
    int A;   // 도우 가격
    int B;   // 토핑 가격
    int C;   // 도우 열량
    int D[100];   // 토핑 열량
    int value;   //총 열량
    int price;   //총 가격
    int temp;   // 스왑

    cin >> N;
    cin >> A;
    cin >> B;
    cin >> C;
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
        int j = i;
        while (j != 0 && D[j] > D[j - 1]) {   // 내림차순 정렬
            temp = D[j - 1];
            D[j - 1] = D[j];
            D[j] = temp;
            j--;
        }
    }
    value = C;
    price = A;
    for (int i = 0; i < N; ++i) {
        if (C / A < D[i] / B) {
            C += D[i];
            A += B;
        }
    }
    cout << C / A;

    return 0;
}