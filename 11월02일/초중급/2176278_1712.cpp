#include <iostream>

using namespace std;

int main() {
	/*입력받기*/
	int A, B, C;
	cin >> A >> B >> C;

	/*출력하기*/
	if (B < C)
		cout << A / (C - B) + 1;
	else //손익분기점 없음.
		cout << -1;


	return 0;
}
