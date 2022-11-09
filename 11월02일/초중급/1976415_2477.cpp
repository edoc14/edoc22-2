#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

pair<int, int> getMaxLen() {

	int rowMax = 0, colMax = 0, rowIdx = 0, colIdx = 0;
	for (int i = 0; i < 6; i++) {
		// 세로
		if (v[i].first == 3 || v[i].first == 4) {
			if (v[i].second > colMax) {
				colMax = v[i].second;
				colIdx = i;
			}
		}
		else {
			if (v[i].second > rowMax) {
				rowMax = v[i].second;
				rowIdx = i;
			}
		}
	}
	pair<int, int> index = { rowIdx, colIdx };
	return index;

}

int getBlankArea() {

	int blank = 0;

	for (int i = 0; i < 6; i++) {
		if (v[i].first == v[(i + 2) % 6].first && v[(i + 1) % 6].first == v[(i + 3) % 6].first) {
			blank = v[(i + 1) % 6].second * v[(i + 2) % 6].second;
		}
	}

	return blank;
}

int getArea() {

	// 가장 긴 변의 index 구하기 (가로, 세로)
	pair<int, int> idx = getMaxLen();
	
	int row = idx.first;
	int col = idx.second;
	 
	// 전체 면적
	int area = v[row].second * v[col].second;
	//cout << "area: " << area << "\n";
	
	int blank = getBlankArea();

	return area - blank;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, type, length;
	v.assign(6, { 0, 0 });

	// 입력
	cin >> K;
	for (int i = 0; i < 6; i++) {
		cin >> v[i].first >> v[i].second;
	}

	// 연산
	int result = getArea();
	result *= K;

	cout << result;

	return 0;
}