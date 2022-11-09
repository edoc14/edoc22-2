#include<stdio.h>
#include<stdlib.h>

int compare(void* a, void* b) { //내림차순 정렬
	if (*(int*)a < *(int*)b) return 1;
	return -1;
}
int main() {
	int n, a, b, c, t[100];
	scanf("%d", &n);
  scanf("%d%d", &a, &b);
  scanf("%d", &c);
	for (int i = 0; i < n; i++) scanf("%d", &t[i]);
	qsort(t, n, sizeof(int), compare);
	double kcal = c, price = a;
	for (int i = 0; i < n; i++) {
		if (kcal / price < (kcal + t[i]) / (price + b)) { // 1원당 열량이 더 커질 경우에만 토핑추가
			kcal += t[i];
			price += b;
		}
	}
	printf("%d", (int)(kcal / price));
	return 0; 
}
