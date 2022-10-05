#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Move {
	int start;
	int end;
} Move;


bool cmp(Move m1, Move m2) {
	if (m1.start != m2.start) {
		return m1.start < m2.start;
	}
	return m1.end < m2.end;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int T, N, s, t, step;
	cin >> T;

	while (T--) {
		cin >> N;

		// N==1이면 무조건 10분
		if (N == 1) {
			cout << "10\n";
			continue;
		}


		// 초기화
		vector<Move> v;
		step = 0;

		// 입력
		for (int i = 0; i < N; i++) {
			cin >> s >> t;
			Move m;
			if (s <= t) {
				m.start = s;
				m.end = t;
			}
			// 역방향으로 옮기는 경우도 존재
			else {
				m.start = t;
				m.end = s;
			}
			v.push_back(m);
		}

		// 정렬 (start 기준)
		sort(v.begin(), v.end(), cmp);

		vector<Move> remain; // 겹쳐서 못 옮기는 테이블 저장용

		// N개를 다 옮길 때까지 반복
		while (!v.empty()) {
			
			v = remain;
			remain.clear(); // 벡터 초기화

			Move table = v[0];

			for (int i = 1; i < v.size(); i++) {
				if (table.end >= v[i].start) {
					remain.push_back(v[i]);
				}
				else {
					table = v[i];
				}
			}

			step++;
		}

		step *= 10;
		cout << step << "\n";

	}

	return 0;
}