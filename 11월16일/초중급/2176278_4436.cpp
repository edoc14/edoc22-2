#include <iostream>
#include <set>

using namespace std;

int main() {
	while (true) {
		long long input;
		cin >> input;
		if (cin.eof() == true)
			break;

		long long temp;
		set<int> s;
		int k = 1;
		while (s.size() < 10) {
			temp = input * k;
			while (temp != 0) {
				s.insert(temp % 10);
				temp /= 10;
			}
			k++;
		}
		cout << k - 1 << "\n";
	}

	return 0;
}
