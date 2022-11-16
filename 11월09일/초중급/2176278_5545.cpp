#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, A, B, C;
	cin >> N; //토핑 개수
	cin >> A >> B; //도우 가격, 토핑 가격
	cin >> C; //도우 열량

	vector<int> D(N); //토핑 열량
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}

	sort(D.begin(), D.end(), greater<int>()); //토핑의 열량을 내림차순 정렬

	int answer = C / A; //1원당 피자 열량 (토핑 0개일 때로 초기화)
	int sum = 0; //토핑 열량의 합

	/*토핑이 k개인 경우 (k!=0)*/
	for (int k = 1; k <= N; k++) {
		sum += D[k - 1];
		answer = max(answer, (C + sum) / (A + B * k));
	}

	cout << answer;

	return 0;
}
