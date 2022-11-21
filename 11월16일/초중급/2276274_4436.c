#include<stdio.h>

int main() {
	int n;
	while (scanf("%lld", &n) != EOF) {
		long long int n1 = n, k = 1;
		int m[10] = { 0 }, Ism = 0;
		while (Ism == 0) {
			while (n1 >= 1) {
				m[n1 % 10] = 1;
				n1 /= 10;
			}
			for (int i = 0; i < 10; i++) {
				if (m[i] == 0) {
					n1 = n * ++k;
					break;
				}
				if (i == 9)Ism = 1;
			}
		}
		printf("%d\n", k);
	}
	return 0; 
}
