#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

char dir[3];
char kingC, kingR, rockC, rockR;
int len;

void direction1(char C) {
	if (C == 'R' && kingC + 1 <= 'H') {
		if (kingC + 1 == rockC && kingR == rockR) {
			if (rockC + 1 <= 'H') {
				kingC++;
				rockC++;
			}
		}
		else {
			kingC++;
		}
	}
	else if (C == 'L' && kingC - 1 >= 'A') {
		if (kingC - 1 == rockC && kingR == rockR) {
			if (rockC - 1 >= 'A') {
				kingC--;
				rockC--;
			}
		}
		else {
			kingC--;
		}
	}
	else if (C == 'T' && kingR + 1 <= '8') {
		if (kingR + 1 == rockR && kingC == rockC) {
			if (rockR + 1 <= '8') {
				kingR++;
				rockR++;
			}
		}
		else {
			kingR++;
		}
	}
	else if (C == 'B' && kingR - 1 >= '1') {
		if (kingR - 1 == rockR && kingC == rockC) {
			if (rockR - 1 >= '1') {
				kingR--;
				rockR--;
			}
		}
		else {
			kingR--;
		}
	}
}

void direction2(char D, char E) {
	if (D == 'R' && E == 'T') {
		if (kingC + 1 <= 'H' && kingR + 1 <= '8') {
			if (kingC + 1 == rockC && kingR + 1 == rockR) {
				if (rockC + 1 <= 'H' && rockR + 1 <= '8') {
					rockC++;
					rockR++;
					kingC++;
					kingR++;
				}
			}
			else {
				kingC++;
				kingR++;
			}
		}
	}
	else if (D == 'L' && E == 'T') {
		if (kingC - 1 >= 'A' && kingR + 1 <= '8') {
			if (kingC - 1 == rockC && kingR + 1 == rockR) {
				if (rockC - 1 >= 'A' && rockR + 1 <= '8') {
					rockC--;
					rockR++;
					kingC--;
					kingR++;
				}
			}
			else {
				kingC--;
				kingR++;
			}
		}
	}
	else if (D == 'R' && E == 'B') {
		if (kingC + 1 <= 'H' && kingR - 1 >= '1') {
			if (kingC + 1 == rockC && kingR - 1 == rockR) {
				if (rockC + 1 <= 'H' && rockR - 1 >= '1') {
					rockC++;
					rockR--;
					kingC++;
					kingR--;
				}
			}
			else {
				kingC++;
				kingR--;
			}
		}
	}
	else if (D == 'L' && E == 'B') {
		if (kingC - 1 >= 'A' && kingR - 1 >= '1') {
			if (kingC - 1 == rockC && kingR - 1 == rockR) {
				if (rockC - 1 >= 'A' && rockR - 1 >= '1') {
					rockC--;
					rockR--;
					kingC--;
					kingR--;
				}
			}
			else {
				kingC--;
				kingR--;
			}
		}
	}
}

int main() {

	int n;

	scanf("%s", dir);
	kingC = dir[0];
	kingR = dir[1];
	scanf("%s", dir);
	rockC = dir[0];
	rockR = dir[1];
	scanf("%d", &n);

	//printf("%c %c %c %c", kingC, kingR, rockC, rockR);

	for (int i = 0; i < n; i++) {
		scanf("%s", dir);
		len = strlen(dir);
		
		if (len == 1) {
			direction1(dir[0]);
		}
		else {
			direction2(dir[0], dir[1]);
		}


	}
	printf("%c%c\n%c%c", kingC, kingR, rockC, rockR);

	return 0;
}
