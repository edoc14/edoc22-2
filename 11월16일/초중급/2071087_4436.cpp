#include <iostream>
#include <cstring>
using namespace std;

int v[10];

int main() {
	long long int n;
	while (cin >> n) {
		//���� ���ڿ��� ó���Ͽ� �տ������� ���ʴ�� ���캻��. 
		memset(v, 0, sizeof(v));
		long long num = n;
		int ans = 0;

		while (!(v[0] && v[1] && v[2] && v[3] && v[4] && v[5] && v[6] && v[7] && v[8] && v[9])) {
			ans++;
			long long nn = num;
			//���� 10���� �����鼭 �������� ���ʴ�� ���캻��.
			while (nn > 0) {
				v[nn % 10] = 1;
				nn /= 10;   
			}
			num += n;
		}
		cout << ans << '\n';
	}
}