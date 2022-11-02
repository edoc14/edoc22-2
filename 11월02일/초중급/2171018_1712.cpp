#include <iostream>

using namespace std;

int main() {
	unsigned long a, b, c;
	cin >> a >> b >> c;
	if (b >= c)
		cout << -1;
	else {
		cout << int(a / (c - b)) + 1;
	}
}
