#include<stdio.h>

int main() {
	int d[6], l[6], k; // 방향, 거리, 참외
	int max_r = 0, max_c = 0; // 가로최대, 세로최대
	scanf("%d", &k);
	int i;
	for (i = 0; i < 6; i++) {
		scanf("%d%d", &d[i], &l[i]);
		if (d[i] >= 3)max_c = max_c > l[i] ? max_c : l[i];
		else max_r = max_r > l[i] ? max_r : l[i];
	}
	int p1 = 0, p2 = 1, p3 = 2, p4 = 3;
	i = 4;
	while (1) {
		if (d[p1] == d[p3] && d[p2] == d[p4]) break;  // 두 방향이 번갈아 나올때까지 찾는다
		p1 = p2;
		p2 = p3;
		p3 = p4;
		p4 = i;
		if (i == 5)i = 0;
		else i++;
	}
	printf("%d", (max_r * max_c - l[p2] * l[p3]) * k); 
	// (가로최대*세로최대)인 큰 사각형의 넓이 - 작은 사각형의 넓이로 면적을 구하고 면적당참외수를 곱해준다
	return 0; 
}
