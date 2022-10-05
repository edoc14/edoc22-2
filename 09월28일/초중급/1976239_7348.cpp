#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
int answer;
vector<int> corridor(201); // ������ �� �� �� ������ ������ ��ȣ�� ���� �迭. 
//i��° ������ ��, �� corridor[i]�� ���� �ش� ������ ���̺��� ������ Ƚ���̴�.

int main() {
	cin >> T;
	while (T--) {
		cin >> N;

		//corridor.clear(); 0���� �ʱ�ȭ.
		for (int i = 1; i <= 200; i++) {
			corridor[i] = 0;
		}

		//�ּ� �ҿ� �ð�. �̵��� �ּ� 1�̹Ƿ� 10���� �ʱ�ȭ.
		int answer = 0;

		while (N--) {
			int s, t;
			cin >> s >> t;

			//corNum_�� i��° �� ���� ���� ��ȣ��, ��ȣ���� (i+1)/2.
			int corNum_s = (s + 1) / 2;
			int corNum_t = (t + 1) / 2;
			if (s > t) { //�׻� corNum_s���� corNum_t������ ũ�� �ʵ��� �ϱ� ���� swap.
				corNum_s = (t + 1) / 2;
				corNum_t = (s + 1) / 2;
			}

			for (int i = corNum_s; i <= corNum_t; i++) {
				//���̺��� �������� ������ �� ��� 1�� �߰�. 
				corridor[i]++;
			}
		}

		//max : ���̺��� ���� ���� ������ ������ ��. 
		//�� answer�� ���� max*10(��)
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