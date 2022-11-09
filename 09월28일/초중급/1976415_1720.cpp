#include <iostream>

using namespace std;

int dp[32], s[32];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	dp[0] = 0; // 타일 크기 0개일 땐 당연히 0개
	dp[1] = 1; // 타일 크기가 1일 땐(2X1) 2X1 하나만 놓을 수 있음
	dp[2] = 3; // 2x2 하나인 경우 + 2x1 2개인 경우 + 1x2 2개인 경우
	
	// 2Xn까지 dp 배열 채우기
	for (int i = 3; i <= n; i++) {
		// 1칸: 2x1 타일로 채우면 됨
		// 2칸: 2x2 타일 하나로 채우는 경우와 2x1 타일 두 개로 채우는 경우
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	}

	// 좌우 대칭인 경우
	s[0] = 0;
	s[1] = 1;
	s[2] = 3;
	s[3] = 1;
	s[4] = 5;

	for (int i = 5; i <= n; i++) {
		// 좌우 대칭이어야 하기 때문에 홀수인 경우는 고려 x
		s[i] = s[i - 2] + 2 * s[i - 4];
	}

	cout << (dp[n] - s[n]) / 2 + s[n] << "\n";

	return 0;
}