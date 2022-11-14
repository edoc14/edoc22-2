#pragma warning (disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;

int topcal[109];
int topcost;
double cal, cost;
double ans;

int main() {

	int n;
	scanf("%d %lf %d %lf", &n, &cost, &topcost, &cal);
	for (int i = 0; i < n; i++) {
		scanf("%d", &topcal[i]);
	}

	sort(topcal, topcal + n, greater<>());

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		while (1) {
			if ((cal + topcal[i]) / (cost + topcost) <= cal / cost || tmp == 1) break;
			else {
				cal += topcal[i];
				cost += topcost;
				tmp++;
			}
		}
	}

	ans = (cal / cost);

	printf("%d", (int)ans);

	return 0;
}

