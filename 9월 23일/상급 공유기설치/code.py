#include<stdio.h>
#include<stdlib.h>

int b[200000];  // 집의 위치를 저장할 배열

int compare(void *first, void *second){  // 오름차순 정렬
    return *(int*)first > *(int*)second ? 1 : -1; 
}

int C(int mid, int c_, int n) {  // mid를 최인접거리로 했을 때 전부 설치가 가능한지 확인하는 함수
	int former = 0;  // b[0]집에서 출발
	for (int i = 1; i < n; i++) {
		if (b[former] + mid <= b[i]) {  // 이전 집에서 mid이상 떨어져 있으면 설치
			former = i;
			c_--;
		}
	}
	return c_ <= 0 ? 1 : 0;
}

int BinarySearch(int left, int right, int c, int n) {  // 이분탐색으로 최인접거리 정하기
	while (left < right) {   
		int mid = (left + right + 1) / 2; 
		if (C(mid, c-1, n) == 1) left = mid;  // 공유기 하나를 출발점에 설치했으므로 c-1을 파라미터로 준다
		else right = mid - 1;
	}
	return left;
}

int main() {
	int n, c, max = 0, min = 1000000001;  // n=집의 수, c=공유기 수
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		max = b[i] > max ? b[i] : max;
        min = b[i] < min ? b[i] : min;
	}
	qsort(b, n, sizeof(int), compare);  // 집의 위치 정렬
	printf("%d", BinarySearch(0, max - min, c, n));  // max - min = 최대거리

	return 0;
}
