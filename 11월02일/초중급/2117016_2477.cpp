#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int k, a, b, v[5] = {0}, remember[2] = {0};
	long long ans = 1;
	int cnt = 0;
	int max1 = 0, max2 = 0, r[2] = { 0 };
	int l = 6;
	cin >> k;
	while (l--) {
		cin >> a >> b;
		if (v[a] != 0) {
			remember[cnt] = b;
			r[cnt++] = a;
		}
		v[a] = b;
	}

	max1 = max(v[1], v[2]);

	max2 = max(v[3], v[4]);
	if (r[0] > 2) {
		l = max2 - remember[0];
	}

	ans = max1 * max2 - l*v[remember[1]];
	return 0;
}