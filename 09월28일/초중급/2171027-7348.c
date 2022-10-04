#include <stdio.h>
int t_result[200];   					//시간을 담을 배열
int main() {
	int T, n, s, t, ns=0;				//ns에는 방문한 마지막 방의 번호를 저장
	scanf("%d", &T);
	for (int j = 0; j < T; j++) {
		int time = 10;					//시간 기본 10분
		scanf("%d", &n);
        	ns=0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &s, &t); 
			if (ns < s) {				//교차 안되는 경우
				t_result[j] = time;		//따로 시간 추가 없음
				ns = t;
			}
			else {						//교차되는 경우
				ns = t;
				time += 10; 			//10분 더해주고
                		t_result[j] = time;		//시간 저장 배열에 시간 저장
			}
		}
	}
	for (int i = 0; i < T; i++)
		printf("%d\n", t_result[i]);
    return 0;
}
