#include <iostream>
#include <cstring>
using namespace std;

int v[10];

int main() {
	long long int n;
	while (cin >> n) {
		//수를 문자열로 처리하여 앞에서부터 차례대로 살펴본다. 
		memset(v, 0, sizeof(v));
		long long num = n;
		int ans = 0;

		while (!(v[0] && v[1] && v[2] && v[3] && v[4] && v[5] && v[6] && v[7] && v[8] && v[9])) {
			ans++;
			long long nn = num;
			//수를 10으로 나누면서 나머지를 차례대로 살펴본다.
			while (nn > 0) {
				v[nn % 10] = 1;
				nn /= 10;   
			}
			num += n;
		}
		cout << ans << '\n';
	}
}