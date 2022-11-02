#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
int answer;
vector<int> corridor(201); // 양쪽의 방 한 쌍 사이의 복도에 번호를 붙인 배열. 
//i번째 복도의 값, 즉 corridor[i]의 값은 해당 복도를 테이블이 지나는 횟수이다.

int main() {
	cin >> T;
	while (T--) {
		cin >> N;

		//corridor.clear(); 0으로 초기화.
		for (int i = 1; i <= 200; i++) {
			corridor[i] = 0;
		}

		//최소 소요 시간. 이동수 최소 1이므로 10으로 초기화.
		int answer = 0;

		while (N--) {
			int s, t;
			cin >> s >> t;

			//corNum_은 i번째 방 앞의 복도 번호로, 번호값은 (i+1)/2.
			int corNum_s = (s + 1) / 2;
			int corNum_t = (t + 1) / 2;
			if (s > t) { //항상 corNum_s값이 corNum_t값보다 크지 않도록 하기 위해 swap.
				corNum_s = (t + 1) / 2;
				corNum_t = (s + 1) / 2;
			}

			for (int i = corNum_s; i <= corNum_t; i++) {
				//테이블이 지나가는 복도의 값 모두 1씩 추가. 
				corridor[i]++;
			}
		}

		//max : 테이블이 가장 많이 지나간 복도의 값. 
		//즉 answer의 값은 max*10(분)
		int max = 0;
		for (int i = 1; i <= 200; i++) {
			if (max < corridor[i])
				max = corridor[i];
		}
		answer = max * 10;

		cout << answer << endl;
	}
	return 0;
}