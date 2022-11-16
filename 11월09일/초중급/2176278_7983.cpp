#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int d; //소요 시간
	int t; //마감일
} task;

bool compare(task a, task b) {
	return a.t > b.t;
}

int main() {
	int n; cin >> n; //과제 개수
	vector<task> task(n); //각 과제의 {소요 시간, 마감}

	for (int i = 0; i < n; i++) {
		cin >> task[i].d >> task[i].t;
	}

	sort(task.begin(), task.end(), compare); //마감 기준으로 내림차순 정렬

	int temp = task[0].t; //날짜 (임시 변수)
	int answer; //연속 휴식 일수
	task.push_back({ 0, 0 });
	
	for (int i = 0; i < n; i++) {
		temp = min(temp, task[i].t) - task[i].d; //늦은 마감부터 과제를 배정하면서
		answer = temp - task[i + 1].t; //연속 휴식 일수 구하기
	}

	cout << answer; //마지막에 구한 연속 휴식 일수가 출력됨.

	return 0;
}
