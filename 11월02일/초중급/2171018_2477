#include <iostream>

using namespace std;

int main() {
	int n, arr[6][2];
	cin >> n;
	int a[2] = { -1, 0 }, b[2] = { -1,0 };
	for (int i = 0; i < 6; i++) {
		cin >> arr[i][0] >> arr[i][1];
		if (i % 2 == 0 && a[1] < arr[i][1]) {
			a[0] = i;
			a[1] = arr[i][1];
		}
		if (i % 2 == 1 && b[1] < arr[i][1]) {
			b[0] = i;
			b[1] = arr[i][1];
		}
	}

	int sub_m = arr[(a[0] + 3) % 6][1] * arr[(b[0] + 3) % 6][1];
	int all_m = arr[a[0]][1] * arr[b[0]][1];
	cout << (all_m - sub_m) * n;
}
