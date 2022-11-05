#include <iostream>
#define ll long long int
using namespace std;

ll A, B, C; //A: 고정비용 B:대당 가변 비용 C: 책정 가격
ll N; //판매량

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