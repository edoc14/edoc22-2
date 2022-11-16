#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, a, b, c, d[101];
	cin >> n;
	cin >> a >> b;
	cin >> c;
	for (int i = 0; i < n; i++)
		cin >> d[i];
	sort(d, d + n, compare);

	int cost = a, cal = c;
	for (int i = 0; i < n; i++) {
		if (cal / cost > (cal + d[i]) / (cost + b)) {
			break;
		}
		cost = cost + b;
		cal = cal + d[i];
	}
	cout << int(cal / cost);
}
