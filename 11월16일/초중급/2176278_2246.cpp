#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> x, pair<int, int> y) {
	if (x.first < y.first) // first 기준 오름차순
		return true;
	else if (x.first > y.first)
		return false;

	else //first 같으면 second 기준 오름차순
		return x.second < y.second;
}

bool compare_temp(pair<int, int> tempC_1, pair<int, int> tempC_2) {
	if (tempC_1.second < tempC_2.second) // second 기준 오름차순
		return true;
	else if (tempC_1.second > tempC_2.second)
		return false;

	else //second 같으면 first 기준 오름차순
		return tempC_1.first < tempC_2.first;
}

int main() {
	/*입력받기*/
	int N; cin >> N;
	vector<pair<int, int>> D(N), C(N); //숙소의 {D, C} 저장, {C, D} 저장
	vector<pair<int, int>> tempD, tempC;
	// tempD: D기준 정렬했을 때, i의 C값이 0~i 중에서 최소인 숙소.
	// tempC: C기준 정렬했을 때, i의 D값이 0~i 중에서 최소인 숙소.
	
	int d, c;
	for (int i = 0; i < N; i++) {
		cin >> d >> c;
		D[i] = { d, c };
		C[i] = { c, d };
	}

	/*풀이*/
	sort(D.begin(), D.end(), compare);
	sort(C.begin(), C.end(), compare);

	int minD = D[0].second;
	int minC = C[0].second;
	for (int i = 0; i < N; i++) {
		if (minD >= D[i].second) {
			tempD.push_back(D[i]);
			minD = D[i].second;
		}
		if (minC >= C[i].second) {
			tempC.push_back(C[i]);
			minC = C[i].second;
		}
	}
	
	/*교집합 원소 개수 찾기*/
	int cnt = 0;
	int idxD = 0, idxC = 0;
	sort(tempC.begin(), tempC.end(), compare_temp); // tempC를 D기준으로 정렬

	while(idxD < tempD.size() && idxC < tempC.size()) {
		if (tempD[idxD].first == tempC[idxC].second && tempD[idxD].second == tempC[idxC].first) { // tempD[i] == tempC[i]
			cnt++;
			idxD++;
			idxC++;
		}
		else if (compare(tempD[idxD], { tempC[idxC].second, tempC[idxC].first } )) // tempD[i] < tempC[i]
			idxD++;
		else  // tempD[i] > tempC[i]
			idxC++;
	}

	cout << cnt;

	return 0;
}
