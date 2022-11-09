#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long a, b, c;

	// 입력
	cin >> a >> b >> c;

	// 손익분기점 없음
	if (b >= c) {
		cout << -1 << "\n";
		return 0;
	}

	long long num = c - b;
	long long result = 0;
	if (num != 0)
		result = a / num;
	result += 1;
	cout << result << "\n";

	return 0;
}