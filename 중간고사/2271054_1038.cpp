#pragma warning (disable:4996)
#include <stdio.h>

int map[11][11];	//구간 당 감소하는 수의 개수
int sum[11];
int r, c;
int flag = 0;
int th;		//현재 몇 번째인지 나타내는 변수 

void makemap() {	//구간 당 감소하는 수의 개수를 담은 배열을 만듦
	//초기값
	for (int i = 0; i < 10; i++) {
		map[1][i] = 1;
	}
	//2차원 그래프 만들기. 행: 자릿수, 열: 맨 앞 자릿수
	for (int i = 2; i <= 10; i++) {		//행
		for (int j = 0; j < 10; j++) {	//열
			//map배열에 바로 할당할 sum 값 저장 (규칙)
			sum[j] = 0;
			for (int k = 0; k < j; k++) {
				sum[j] += map[i - 1][k];
			}
			map[i][j] = sum[j];
		}
	}

}

void combination(int n) {
	if (n == 0) return;

	// 내림차순 수열....어떻게 할까
	combination(n - 1);
	

}
 
int main() {

	int n;
	scanf("%d", &n);
	int tmp = n;

	makemap();
	
	//check//
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	while (1) {	//자릿수와 가장 큰 자리 숫자 구함. 
		if (tmp == 0) break;
		else if (tmp == 1) c = tmp;
		tmp /= 10;
		r++;
	}

	for (int i = 1; i <= r; i++) {	//구간 내에서 구해야 할 감소하는 수: n번째
		for (int j = 0; j < c - 1; j++) {
			n -= map[i][j];
		}
	}

	if (r > 9) printf("-1");	//10자리 부터는 존재하지 않음. 
	else if (r == 1) printf("%d", n);	//한 자리수는 그대로 출력
	else {	//구간 내에서 몇 번째인지
		combination(n);
		flag = 1;
	}

	return 0;
}
// 자릿수/맨앞자릿수
// 
// 한 자리
// 0 1 2 3 4 5 6 7 8 9
// 1 1 1 1 1 1 1 1 1 1 
// 
// 두 자리
// 0 1 2 3 4 5 6 7 8 9 
// 0 1 2 3 4 5 6 7 8 9
// 
// 세 자리
// 0 1 2 3 4 5 6 7 8 9
// 0 0 1 3 6 1015...
// 
// 두 자리
// 

