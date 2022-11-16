#include<stdio.h>
#include<stdlib.h>

int dt[1000000][2];
int compare(void* a, void* b) {
	if (((int*)a)[1] < ((int*)b)[1]) return 1;
	return -1;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &dt[i][0], &dt[i][1]);
	qsort(dt, n, sizeof(int) * 2, compare);

	for (int i = 1; i < n; i++) {
		int over = dt[i - 1][1] - dt[i][1] - dt[i - 1][0];
		if (over < 0) dt[i][1] += over;
	}
	printf("%d", dt[n - 1][1] - dt[n - 1][0]);
	return 0; 
}
