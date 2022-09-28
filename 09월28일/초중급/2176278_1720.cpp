#include <iostream>
#include <vector>
#define MAX 31

using namespace std;

int main() {
	/*입력받기*/
	int N; cin >> N;
	int d[MAX], s[MAX]; //dp배열 : 전체 경우의 개수, symmetric배열 : 대칭인 경우의 개수 (뒤집었을 때 자기 자신 나오는 경우)

	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= N; i++) {
		d[i] = d[i - 1] + 2 * d[i - 2];
	}

	s[1] = 1;
	s[2] = 3;
	for (int i = 3; i <= N; i++) {
		if(i % 2 == 1) //i 홀수일 때
			s[i] = d[i / 2];
		else //i 짝수일 때
			s[i] = 2 * d[i / 2 - 1] + d[i / 2];
	}

	int result = (d[N] - s[N]) / 2 + s[N];

	/*출력하기*/
	cout << result;

	return 0;
}
