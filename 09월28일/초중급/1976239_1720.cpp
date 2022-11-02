//Reference: https://lotuslee.tistory.com/129
#include <iostream>
using namespace std;
int N;

/*
* 모든 타일배치는  '점대칭(즉 제외되어야 하는 좌우대칭)'인 경우 X와  '선대칭'인 경우 Y 두 가지로 나뉨.
- (전체 경우의 수) = 2 * X + Y
- (구해야하는 정답) = X + Y
* 따라서 {(전체 경우의 수) - Y }/2 = X + Y 의 원리를 이용하기 위해, 선대칭인 경우의 수를 따로 구한다.
* DP를 이용한다
*/

int total[31]; //중복 고려하지 않은 전체 경우의 수.
int sym[31]; //선대칭 경우의 수
int ans;

int main() {
	cin >> N;

	total[1] = 1;
	total[2] = 3;

	//전체 경우의 수 total[N] = total[N-1] + 2*total[N-2]
	for (int i = 3; i <= N; i++) {
		total[i] = total[i - 1] + 2 * total[i - 2];
		cout << "total[" << i << "] = " << total[i] << endl;
	}

	//선대칭 경우의 수 : 전체 경우의 수와 유사함. (sym[n] = sym[n-2] + 2* sym[n-4]
	sym[1] = 1;	sym[2] = 3;
	sym[3] = 1;	sym[4] = 5;
	for (int n = 5; n <= N; n++) {
		sym[n] = sym[n - 2] + 2 * sym[n - 4];
		cout << "sym[" << n << "] = " << sym[n] << endl;
	}

	ans = (total[N] - sym[N]) / 2 + sym[N];
	cout << ans << endl;
}