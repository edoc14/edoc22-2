#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	육각형 넓이 구하는 게 관건.

	육각형 --> 예시처럼 꺾인 ㄱ 모양밖에 안 됨. 그거 회전한 거랑. --> 총 4가지.
	접근: (전체 사각형 넓이) - (작은 사각형 넓이)

	전체 사각형 넓이 :
		= 가로방향 중 제일 큰 길이 * 세로방향 중 제일 큰 길이

	작은 사각형 넓이 :
		방향이 (ex- 1313)이런 식으로, 2개씩 2번 반복됨. --> 작은 사각형!
*/


int main() {
	int K; cin >> K;
	int width = 0, height = 0; //전체 사각형 너비, 높이
	int a_arr[6], b_arr[6]; //방향, 길이 배열
	int big, small; //전체, 작은 사각형 넓이

	for (int i = 0; i < 6; i++) {
		int a, b; //방향, 길이
		cin >> a_arr[i]>> b_arr[i];

		if (a_arr[i] < 3) //동쪽, 서쪽
			width = max(width, b_arr[i]);
		if (a_arr[i] > 2) //남쪽, 북쪽
			 height = max(height, b_arr[i]);
	}

	big = width * height;

	for (int i = 0; i < 6; i++) {
		if (a_arr[i] == a_arr[(i + 2) % 6]
			&& a_arr[(i + 1) % 6] == a_arr[(i + 3) % 6])
			small = b_arr[(i + 1) % 6] * b_arr[(i + 2) % 6];
	}

	cout << K * (big - small);

	return 0;
}
