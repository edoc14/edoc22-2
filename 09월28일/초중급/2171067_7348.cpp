#include <iostream>
#include <algorithm>
using namespace std;
int dp[200];
int main() {
	int test, num, start, dst;
	cin >> test;
	for (int t = 0; t < test; t++) {
		for (int i = 0; i < 200; i++)
			dp[i] = 0;
		cin >> num;
		for (int k = 0; k < num; k++) {
			cin >> start >> dst;
			int temp;
			if (start > dst) {
				temp = dst;
				dst = start;
				start = temp;
			}
			start = (start - 1) / 2;
			dst = (dst - 1) / 2;
			for (int i = start; i <= dst; i++)
				dp[i] += 10;
		}
		int result = 0;
		for (int i = 0; i < 200; i++)
			result = max(result, dp[i]);
		cout << result << '\n';
	}

	return 0;
}