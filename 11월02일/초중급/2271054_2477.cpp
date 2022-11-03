#pragma warning (disable:4996)
#include <stdio.h>

int M1 = 0, M2 = 0, M1idx = 0, M2idx = 0;
int area = 0, notarea = 0;
int len[7];

int main() {

	int num;
	int tmp;
	scanf("%d", &num);

	for (int i = 0; i < 6; i++) {
		scanf("%d %d",&tmp, &len[i]);

		if ((tmp == 3 || tmp == 4) && len[i] > M1) {
			M1 = len[i];
			M1idx = i;
		}
		else if ((tmp == 2 || tmp == 1) && len[i] > M2) {
			M2 = len[i];
			M2idx = i;
		}

		/*if (len[i] > M1) {
			M2 = M1;
			M1 = len[i];
			M2idx = M1idx;
			M1idx = i;
		}
		else if (len[i] > M2) {
			M2 = len[i];
			M2idx = i;
		}
		*/

	}

	// printf("%d %d %d %d %d %d\n", M1, M2, M1idx, M2idx, len[M1idx], len[M2idx]);

	if (M1idx >= 3) M1idx -= 3;	//최대1-3
	else M1idx += 3;
	if (M2idx >= 3) M2idx -= 3;	//최대2-2
	else M2idx += 3;

	notarea = len[M1idx] * len[M2idx];
	area = M1 * M2;

	// printf("%d %d %d %d %d %d\n", M1, M2, M1idx, M2idx, len[M1idx], len[M2idx]);
	printf("%d", (area - notarea) * num);

	// 0 1 2 3 4 5

	/*
	1
	2 5
	3 5
	1 1
	4 2
	1 4
	4 3
	*/

	return 0;
}
