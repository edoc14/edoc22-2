#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	
	/*예외 처리*/
	if (N < 10) {
		cout << N;
		return 0; //프로그램 종료
	}
	else if (N > 1022) { //가장 큰, 감소하는 수 (이게 1022번째)
		cout << -1;
		return 0; //프로그램 종료
	}

	/*arr배열 채우기*/
	int arr[11][10]; //arr[총 자릿수][맨 앞자리 숫자] = (그 상황의) 감소하는 수 개수
	int arr_sum[11]; //arr_sum[i] = arr[i][전체] 값들의 합
	int num = 0; //여태까지 센 감소하는 수의 총 개수
	bool flag = true; //false이면 이중for문 탈출
	int temp_i; //탈출 시의 i, j 저장

	for (int j = 0; j < 10; j++) {
		arr[0][j] = 1;
		if (j == 0) continue; //j == 0이면 num = 0이어야 하기 때문.
		num += arr[0][j];
	}
	arr_sum[0] = 9;

	for (int i = 1; i < 11 && flag; i++) {
		arr_sum[i] = 0;
		for (int j = 0; j < 10 && flag; j++) {
			if (j == 0)
				arr[i][j] = 0;
			else {
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
				num += arr[i][j];
				arr_sum[i] += arr[i][j];
				if (num >= N) {
					cout << j; //N번째 감소하는 수의 맨 앞자리 숫자
					N = N - arr_sum[i - 1];
					temp_i = i;
					flag = false;
				}
			}
		}
	}

	/*N번째 감소하는 수를 출력하기 (앞에서 2번째 자리부터)*/
	for (int i = temp_i - 1; i >= 0; i--) {
		if (N == 0) break;

		/*num 초기화*/
		if (i == 0)
			num = 0;
		else
			num = arr_sum[i - 1];

		/*출력할 숫자 구하기*/
		for (int j = 0; j < 10; j++) {
			num += arr[i][j];
			if (num >= N) {
				cout << j; //N번째 감소하는 수의 맨 앞자리 숫자
				N = N - arr_sum[i - 1];
				break;
			}
		}
	}

	return 0;
}
