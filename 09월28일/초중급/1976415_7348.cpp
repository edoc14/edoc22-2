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

	// �Է�
	int T, N, s, t, step;
	cin >> T;

	while (T--) {
		cin >> N;

		// N==1�̸� ������ 10��
		if (N == 1) {
			cout << "10\n";
			continue;
		}


		// �ʱ�ȭ
		vector<Move> v;
		step = 0;

		// �Է�
		for (int i = 0; i < N; i++) {
			cin >> s >> t;
			Move m;
			if (s <= t) {
				m.start = s;
				m.end = t;
			}
			// ���������� �ű�� ��쵵 ����
			else {
				m.start = t;
				m.end = s;
			}
			v.push_back(m);
		}

		// ���� (start ����)
		sort(v.begin(), v.end(), cmp);

		vector<Move> remain; // ���ļ� �� �ű�� ���̺� �����

		// N���� �� �ű� ������ �ݺ�
		while (!v.empty()) {
			
			v = remain;
			remain.clear(); // ���� �ʱ�ȭ

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