#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
	if (((int*)a)[0] > ((int*)b)[0]) return 1; //오름차순
	return 0;
}
int n[10000][2];
int main() {
	int N, c, d, res = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &n[i][0], &n[i][1]);
	qsort(n, N, 8, compare);
	for (int i = 0; i < N; i++) {
		int a = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (n[i][1] >= n[j][1]) { //첫번째 조건
				a = 0;
				break;
			}
		}
		if (a) {
			for (int j = 0; j < N; j++) {
				if (i == j)continue;
				if (n[i][1] > n[j][1]) { //두번째 조건
					if (n[i][0] >= n[j][0]) {
						a = 0;
						break;
					}
				}
			}
		}
		if (a)res++;
	}
	printf("%d", res);
	return 0; 
}
