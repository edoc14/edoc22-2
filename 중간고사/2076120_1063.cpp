#include<iostream>
#include<string.h>
using namespace std;

int main() {
	int n;
	string s;
	pair<int, int> king, stone;
	cin >> s;
	king.first = s[0] - 'A' + 1, king.second = s[1] - '0';
	cin >> s;
	stone.first = s[0] - 'A' + 1, stone.second = s[1] - '0';
	cin >> n;

	while (n--) {
		char st[5];
		cin >> st;
		if (!strcmp(st, "R")) {
			if (king.first == 8 || (king.second == stone.second && king.first == 7 && stone.first == 8))
				continue;
			if (stone.first - king.first == 1)
				stone.first++;
			king.first++;
		}
		else if (!strcmp(st, "L")) {
			if (king.first == 1 || (king.second == stone.second && king.first == 2 && stone.first == 1))
				continue;
			if (stone.first - king.first == -1)
				stone.first--;
			king.first--;
		}
		else if (!strcmp(st, "B")) {
			if (king.second == 1 || (king.first == stone.first && king.second == 2 && stone.second == 1))
				continue;
			if (stone.second - king.second == -1)
				stone.second--;
			king.second--;
		}
		else if (!strcmp(st, "T")) {
			if (king.second == 8 || (king.first == stone.first && king.second == 7 && stone.second == 8))
				continue;
			if (stone.second - king.second == 1)
				stone.second++;
			king.second++;
		}
		else if (!strcmp(st, "RT")) {
			if (king.first == 8 || king.second == 8 || (king.second == 7 && stone.second == 8 && king.first == 7 && stone.first == 8))
				continue;
			if (stone.first - king.first == 1 && stone.second - king.second == 1)
				stone.first++, stone.second++;
			king.first++, king.second++;
		}
		else if (!strcmp(st, "LT")) {
			if (king.first == 1 || king.second == 8 || (king.second == 7 && stone.second == 8 && king.first == 2 && stone.first == 1))
				continue;
			if (stone.first - king.first == -1 && stone.second - king.second == 1)
				stone.first--, stone.second++;
			king.first--, king.second++;
		}
		else if (!strcmp(st, "RB")) {
			if (king.first == 8 || king.second == 1 || (king.second == 2 && stone.second == 1 && king.first == 7 && stone.first == 8))
				continue;
			if (stone.first - king.first == 1 && stone.second - king.second == -1)
				stone.first++, stone.second--;
			king.first++, king.second--;
		}
		else if (!strcmp(st, "LB")) {
			if (king.first == 1 || king.second == 1 || (king.second == 2 && stone.second == 1 && king.first == 2 && stone.first == 1))
				continue;
			if (stone.first - king.first == -1 && stone.second - king.second == -1)
				stone.first--, stone.second--;
			king.first--, king.second--;
		}
	}
	cout << (char)(king.first + 'A' - 1) << king.second << "\n";
	cout << (char)(stone.first + 'A' - 1) << stone.second;
}