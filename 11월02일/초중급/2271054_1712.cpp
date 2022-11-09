#pragma warning (disable:4996)
#include <stdio.h>

int h[4], w[4];
int Mh = 0, Mw = 0, Mh_idx, Mw_idx;

int main() {

	int num;
	int dir, dist;
	scanf("%d", &num);

	int j = 0, k = 0;	//h, w
	for (int i = 0; i < 6; i++) {

		scanf("%d %d", &dir, &dist);
		if (dir == 4 || dir == 3) {
			h[j] = dist;
			j++;
		}
		else {
			w[k] = dist;
			k++;
		}

		if ((dir == 4 || dir == 3) && Mh < dist) {
			Mh = dist;
			Mh_idx = j;
		}
		if ((dir == 1 || dir == 2) && Mw < dist) {
			Mw = dist;
			Mw_idx = k;
		}


	}


	//printf("%d %d %d\n%d %d %d", Mh, h[Mh_idx], Mh_idx, Mw, w[Mw_idx], Mw_idx);

	if (Mh_idx - 1 < 0) {
		Mh_idx += 2;
	}
	else {
		Mh_idx -= 1;
	}
	if (Mw_idx - 2 < 0) {
		Mw_idx += 1;
	}
	else {
		Mw_idx -= 2;
	}

	printf("%d %d %d\n%d %d %d\n", Mh, h[Mh_idx], Mh_idx, Mw, w[Mw_idx], Mw_idx);
	
	printf("%d", h[Mh_idx] * w[Mw_idx]);

	return 0;
}
