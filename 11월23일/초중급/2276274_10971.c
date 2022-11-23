#include<stdio.h>

int N, w[10][10], v[10] = { 0 }, res = 0, tmp = 0;

void bt(int i, int ii, int m) {
	v[i] = 1;
	for (int j = 0; j < N; j++) {
		if (w[i][j] != 0 && v[j] == 0) {
			tmp += w[i][j];
			bt(j, ii, w[i][j]);
		}
	}
	for (int j = 0; j < N; j++) {
		if (v[j] == 0) {
			v[i] = 0;
			tmp -= m;
			return;
		}
	}
	if (w[i][ii] == 0) {
		v[i] = 0;
		tmp -= m;
		return;
	}
	tmp += w[i][ii];
	if (res == 0 || res > tmp) res = tmp;
	v[i] = 0;
	tmp -= m + w[i][ii];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &w[i][j]);
	for (int i = 0; i < N; i++) bt(i,i, 0);
	printf("%d", res);
	return 0; 
}
