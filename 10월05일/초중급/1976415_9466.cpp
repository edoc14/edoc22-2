#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> student;
vector<bool> check, group;
int cnt;

void function (int n) {

	// 다음 학생
	int next = student[n].second;
	check[n] = true; // 방문 표시(학생)

	// 아직 방문 안 한 학생이면
	if (check[next] == false) {
		function(next);
	}
	// 이미 방문한 사이클이 아니라면(처음 방문한 사이클이면)
	else if (group[next] == false) {
		int tmp = next;
		// 사이클에 있는 학생수 count
		while (tmp != n) {
			cnt++;
			tmp = student[tmp].second;
		}
		cnt++;
	}

	// 사이클도 방문 표시
	group[n] = true;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n, ans;
	
	// 입력
	cin >> T;

	while (T--) {
		// 입력
		cin >> n;
		student.assign(n + 1, {0, 0});
		for (int i = 1; i <= n; i++) {
			cin >> student[i].second;
			student[i].first = i;
		}

		// 초기화
		cnt = 0;
		check.assign(n + 1, false);
		group.assign(n + 1, false);

		// 연산
		for (int i = 1; i <= n; i++) {
			if (check[i] == false)
				function(i);
		}


		ans = n - cnt;
		cout << ans << "\n";
	}
	

	return 0;
}