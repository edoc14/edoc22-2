#include <iostream>
#define ll long long int
using namespace std;

ll A, B, C; //A: ������� B:��� ���� ��� C: å�� ����
ll N; //�Ǹŷ�

int main() {
	cin >> A >> B >> C;
	if (B >= C) {
		cout << -1;
		return 0;
	}

	double doubleN = (double)A / (double)(C - B);
	N = (ll)doubleN + 1;

	cout << N;
	return 0;
}