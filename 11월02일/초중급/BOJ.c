#include<stdio.h>

int main() {
	int a, b, c, res;
	scanf("%d%d%d", &a, &b, &c);
	if (b >= c) res = -1;
	else  res = a / (c - b) + 1;
	printf("%d", res);
	return 0; //전희원
}