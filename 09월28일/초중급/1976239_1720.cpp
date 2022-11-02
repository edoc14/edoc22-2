//Reference: https://lotuslee.tistory.com/129
#include <iostream>
using namespace std;
int N;

/*
* ��� Ÿ�Ϲ�ġ��  '����Ī(�� ���ܵǾ�� �ϴ� �¿��Ī)'�� ��� X��  '����Ī'�� ��� Y �� ������ ����.
- (��ü ����� ��) = 2 * X + Y
- (���ؾ��ϴ� ����) = X + Y
* ���� {(��ü ����� ��) - Y }/2 = X + Y �� ������ �̿��ϱ� ����, ����Ī�� ����� ���� ���� ���Ѵ�.
* DP�� �̿��Ѵ�
*/

int total[31]; //�ߺ� ������� ���� ��ü ����� ��.
int sym[31]; //����Ī ����� ��
int ans;

int main() {
	cin >> N;

	total[1] = 1;
	total[2] = 3;

	//��ü ����� �� total[N] = total[N-1] + 2*total[N-2]
	for (int i = 3; i <= N; i++) {
		total[i] = total[i - 1] + 2 * total[i - 2];
		cout << "total[" << i << "] = " << total[i] << endl;
	}

	//����Ī ����� �� : ��ü ����� ���� ������. (sym[n] = sym[n-2] + 2* sym[n-4]
	sym[1] = 1;	sym[2] = 3;
	sym[3] = 1;	sym[4] = 5;
	for (int n = 5; n <= N; n++) {
		sym[n] = sym[n - 2] + 2 * sym[n - 4];
		cout << "sym[" << n << "] = " << sym[n] << endl;
	}

	ans = (total[N] - sym[N]) / 2 + sym[N];
	cout << ans << endl;
}