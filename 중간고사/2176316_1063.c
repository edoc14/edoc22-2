#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

int map[8][8];
// r, l, b, t, rt, lt, rb, lb
int dx[8] = {0, 0, +1, -1, -1, -1, +1, +1};
int dy[8] = {+1, -1, 0, 0, +1, -1, +1, -1};
char inputKy, inputSy;
int inputKx, inputSx, n;
vector<string> moves;
int main() {
	scanf("%c%d %c%d %d", &inputKy, &inputKx, &inputSy, &inputSx, &n);
	int kx = 8- inputKx; int ky = inputKy - 'A';
	int sx = 8 - inputSx; int sy = inputSy - 'A';

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		moves.push_back(str);
	}
	for (int m = 0; m < n; m++) {
		string move = moves[m];
		int i = 0;
		if (move == "R") {

		}
		else if (move == "L") {
			i += 1;
		}
		else if (move == "B") {
			i += 2;
		}
		else if (move == "T") {
			i += 3;
		}
		else if (move == "RT") {
			i += 4;
		}
		else if (move == "LT") {
			i += 5;
		}
		else if (move == "RB") {
			i += 6;
		}
		else {
			i += 7;
		}
		int nx = kx + dx[i];
		int ny = ky + dy[i];
		
		if (nx < 0 || nx > 7 || ny < 0 || ny > 7 ) {
			continue;
		}
		if (nx == sx && ny == sy) {
			int nsx = sx + dx[i];
			int nsy = sy + dy[i];
			if (nsx < 0 || nsx >7 || nsy < 0 || nsy >7) {
				continue;
			}
			else {
				sx = nsx; sy = nsy;
			}
		}
		kx = nx; ky = ny;
	}
	printf("%c%d\n", 'A' + ky, 8 - kx);
	printf("%c%d", 'A' + sy, 8 - sx);
	return 0;
}
