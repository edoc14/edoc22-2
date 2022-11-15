#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<string> v;

bool cmp(string s1, string s2) {
	if (s1.length() == s2.length()) {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == s2[i])
				continue;
			return s1[i] < s2[i];
		}
	}
	return s1.length() < s2.length();
}

void backtracking(bool check[10], int start) {
	string s = "";
	
	for (int i = 9; i >= 0; i--) {
		if (check[i])
			s += ('0' + i);
	}
	v.push_back(s);

	for (int i = start; i < 10; i++) {
		if (check[i] == false) {
			check[i] = true;
			backtracking(check, i + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	if (n > 1022) {
		cout << "-1\n";
		return 0;
	}

	bool check[10] = {};
	backtracking(check, 0);
	sort(v.begin(), v.end(), cmp);
	cout << v[n + 1] << "\n";
	return 0;
}