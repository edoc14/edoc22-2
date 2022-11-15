#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

string k, r;
int n;
vector<string> v;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> k >> r >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	pair<int, int> king, rock;
	king.first = '8' - k[1];
	king.second = k[0] - 'A';
	rock.first = '8' - r[1];
	rock.second = r[0] - 'A';

	string move;
	int dir = 0;
	for (int i = 0; i < n; i++) {
		move = v[i];

		if (!move.compare("R")) {
			dir = 0;
		}
		else if (!move.compare("L")) {
			dir = 1;
		}
		else if (!move.compare("B")) {
			dir = 2;
		}
		else if (!move.compare("T")) {
			dir = 3;
		}
		else if (!move.compare("RT")) {
			dir = 4;
		}
		else if (!move.compare("LT")) {
			dir = 5;
		}
		else if (!move.compare("RB")) {
			dir = 6;
		}
		else if (!move.compare("LB")) {
			dir = 7;
		}
 
		int x = king.first + dx[dir];
		int y = king.second + dy[dir];

		if (x < 0 || x > 7 || y < 0 || y > 7)
			continue;

		if (x == rock.first && y == rock.second) {
			int rx = rock.first + dx[dir];
			int ry = rock.second + dy[dir];

			if (rx < 0 || rx > 7 || ry < 0 || ry > 7)
				continue;

			rock.first = rx;
			rock.second = ry;
		}
		king.first = x;
		king.second = y;
	}

	cout << (char)(king.second + 'A') << 8 - king.first << "\n";
	cout << (char)(rock.second + 'A') << 8 - rock.first << "\n";

	return 0;

}