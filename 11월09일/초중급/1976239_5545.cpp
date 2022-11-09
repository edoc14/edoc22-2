#include <iostream>
#include <vector>
using namespace std;

int N; //1<=N<=100 //토핑 종류 수 //같은 토핑 1개씩만 or 0개
int A, B; //1<=A,B<=1000 //A: 도우 가격, B: 토핑 가격
int C; //도우 열량
vector<int> D; //토핑별 열량 (총 N줄) 

//피자 가격 = A + B * k(선택한 토핑 개수)
//피자 열량 = C + D * k


int main() {
	cin >> N >> A >> B >> C;
	for (int i = 1; i <= N; i++) cin >> D[i];

	

	int price = A + ; //최고의 피자 가격
	int cal = C + ; //최고의 피자 열량
	int result = cal / price; //'최고의 피자'의 1원당 열량
	cout << result;
	return 0;
}