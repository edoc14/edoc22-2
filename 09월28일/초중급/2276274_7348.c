#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {  // qsort 비교함수(오름차순)
	if (((int*)a)[0] > ((int*)b)[0]) return 1;
	else return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n, res = 0;
		int move[200][2]; // [시작지점, 도착지점]
		int cmove[200][2]; // 임시배열
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a > b) {  // 시작지점 < 도착지점 으로 정렬
				int temp = a;
				a = b;
				b = temp;
			}
			move[j][0] = a % 2 ? a : a - 1;
			move[j][1] = b % 2 ? b : b - 1;
			// 짝수일때 -1을 해주어 마주보는 방을 같은 방으로 취급한다
		}
		qsort(move, n, sizeof(int) * 2, compare); // 시작지점이 작은 순으로정렬

		int pre = 0; // 이전 move
		int c_move = n; // 겹치는 move 수, 넣은 값은 보정차원, 신경쓸 필요x
		while (c_move != 0) {
			n = c_move;
			pre = 0, c_move = 0;
			for (int j = 1; j < n; j++) {
				if (move[j][0] > move[pre][1])pre = j;
				// 시작지점이 이전 move의 도착지점보다 크면 move
				else {
					cmove[c_move][0] = move[j][0];
					cmove[c_move++][1] = move[j][1];
					// 아니면 임시배열에 저장, 겹치는 move 수 +1
				}
			}
			res++; // 시간 +10분
			for (int j = 0; j < c_move; j++) {
				move[j][0] = cmove[j][0];
				move[j][1] = cmove[j][1];
				// 임시배열의 값을 다시 원래 배열로 옮기기
			}
		}

		printf("%d\n", res * 10);
	}
	return 0;
}
