#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> student;
vector<bool> check, group;
int cnt;

void function (int n) {

	// ���� �л�
	int next = student[n].second;
	check[n] = true; // �湮 ǥ��(�л�)

	// ���� �湮 �� �� �л��̸�
	if (check[next] == false) {
		function(next);
	}
	// �̹� �湮�� ����Ŭ�� �ƴ϶��(ó�� �湮�� ����Ŭ�̸�)
	else if (group[next] == false) {
		int tmp = next;
		// ����Ŭ�� �ִ� �л��� count
		while (tmp != n) {
			cnt++;
			tmp = student[tmp].second;
		}
		cnt++;
	}

	// ����Ŭ�� �湮 ǥ��
	group[n] = true;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n, ans;
	
	// �Է�
	cin >> T;

	while (T--) {
		// �Է�
		cin >> n;
		student.assign(n + 1, {0, 0});
		for (int i = 1; i <= n; i++) {
			cin >> student[i].second;
			student[i].first = i;
		}

		// �ʱ�ȭ
		cnt = 0;
		check.assign(n + 1, false);
		group.assign(n + 1, false);

		// ����
		for (int i = 1; i <= n; i++) {
			if (check[i] == false)
				function(i);
		}


		ans = n - cnt;
		cout << ans << "\n";
	}
	

	return 0;
}