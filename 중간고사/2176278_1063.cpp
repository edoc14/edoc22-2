#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string move(string obj, string direction) {
	/*이동*/
	if(direction[0] == 'L' || direction[1] == 'L') {
		obj[0] -= 1; //왼쪽
	}
	if (direction[0] == 'R' || direction[1] == 'R') {
		obj[0] += 1; //오른쪽
	}
	if (direction[0] == 'B' || direction[1] == 'B') {
		obj[1] -= 1; //아래
	}
	if (direction[0] == 'T' || direction[1] == 'T') {
		obj[1] += 1; //위
	}

	/*체스판 밖으로 벗어나면*/
	if (obj[0] < 'A' || obj[0] > 'H' || obj[1] < '1' || obj[1] > '8')
		return "error";

	return obj;
}

int main() {
	string king, stone;
	cin >> king >> stone;
	int N;
	cin >> N;

	string input, tempK, tempS;

	while (N--) {
		cin >> input;

		/*현재 위치 저장*/
		tempK = king;
		tempS = stone;

		/*이동*/
		king = move(king, input);
		if (king == stone) {
			stone = move(stone, input);
		}

		/*체스판 밖으로 벗어나면 위치 원래대로*/
		if (king == "error" || stone == "error") {
			king = tempK;
			stone = tempS;
		}
	}

	cout << king << "\n" << stone;

	return 0;
}
