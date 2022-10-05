#include <iostream>

using namespace std;

int dp[32], s[32];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	dp[0] = 0; // Ÿ�� ũ�� 0���� �� �翬�� 0��
	dp[1] = 1; // Ÿ�� ũ�Ⱑ 1�� ��(2X1) 2X1 �ϳ��� ���� �� ����
	dp[2] = 3; // 2x2 �ϳ��� ��� + 2x1 2���� ��� + 1x2 2���� ���
	
	// 2Xn���� dp �迭 ä���
	for (int i = 3; i <= n; i++) {
		// 1ĭ: 2x1 Ÿ�Ϸ� ä��� ��
		// 2ĭ: 2x2 Ÿ�� �ϳ��� ä��� ���� 2x1 Ÿ�� �� ���� ä��� ���
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	}

	// �¿� ��Ī�� ���
	s[0] = 0;
	s[1] = 1;
	s[2] = 3;
	s[3] = 1;
	s[4] = 5;

	for (int i = 5; i <= n; i++) {
		// �¿� ��Ī�̾�� �ϱ� ������ Ȧ���� ���� ��� x
		s[i] = s[i - 2] + 2 * s[i - 4];
	}

	cout << (dp[n] - s[n]) / 2 + s[n] << "\n";

	return 0;
}