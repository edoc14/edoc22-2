/*
* 백준 7983 내일할거야
* 입력 사항 
* n => 과제 개수
* i => 과제 index , d => 과제가 걸리는 일 수 
* t => 과제의 due date
* 최대 며칠동안 놀 수 있는지 구하는 알고리즘
* // 기능 목록
* 1. 과제 개수 입력 받기 [*]
* 2. 과제 개수 만큼 d와 t 입력 받기 [*]
* -- 삽질 -- 
* 가장 due date이 가까운 것: 놀 수 있는 날짜가 가장 적은 과제?
* ----------
* 런타임 에러 발생! 
* 만약 일해야 하는 기간이 겹치면 놀아야하는 일 수에서 겹치는 일 빼줘야 함.
* 10일 4일 / 8일 3일 이면 => 7,8,9,10/ 5,6,7.. 
* 그러면 일해야하는 날을 저장해두고?  겹치는게 있으면 playPersign을 -1해주는 거지.
* 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_SIZE 1000000

int* getInput(int n){
	int playPerAssign[MAX_SIZE];
	int input[2] = {0, };
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> input[0] >> input[1];
		playPerAssign[i] = input[1]- input[0];
		for (int j = input[2]; j < input[1]; j++) {
			if (v.end() == find(v.begin(), v.end(), j)) {
				playPerAssign[i]--;
				v.push_back(j - 1);

			}
			v.push_back(j);
		}
	}
	return min_element(begin(playPerAssign), end(playPerAssign));
}
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> day;
	int* playDay = getInput(n);
	cout << &playDay;
}