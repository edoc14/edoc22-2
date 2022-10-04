#include <iostream>
#include <algorithm>

using namespace std;

//매개변수 탐색, 이분탐색
/*
	구하려는 값 : 가장 인접한 두 공유기 사이의 거리 <-- 얘가 최대일 때, 그 최댓값을 출력해야 함.

	매개변수 탐색
	--> 그 거리가 x라고 하자. 가능해?
		안 되면		 y라고 하자. 가능해?
		안 되면		 z이라 하자. 가능해?

	이분탐색 이용 --> x, y, z ... 정하기
*/

int N, C; //집 개수, 공유기 개수
int house[200000]; //집 위치

string check(int mid) { //거리 == mid라고 가정하고 해봤는데, 되나 안 되나?
	int place = house[0]; //직전에 공유기 설치한 집 위치
	int num = 1; //설치한 공유기 개수

	for (int i = 0; i < N; i++) {
		if(house[i] - place < mid)
			continue;
		place = house[i];
		num++;
	}

	if (num < C) //공유기 다 설치 못했는데 더이상 집이 없어 --> 거리 줄여보자
		return "low";
	else  //공유기 다 설치함 --> 늘려서 다시 시도
		return "high";
 }


int main() {
	/*입력받기*/
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
	sort(house, house + N); //집 간격 구하려면 정렬 필요함.
	

	/*매개변수 탐색*/
	int left = 1;
	int right = house[N - 1] - house[0];
	int mid;

	while (left < right) {
		mid = (left + right+1) / 2;

		string ch = check(mid);
		if (ch == "high") //거리 늘려야
			left = mid;

		if (ch == "low") //거리 줄여야
			right = mid - 1;
	}

	cout << left;

	return 0;
}
