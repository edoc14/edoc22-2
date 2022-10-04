#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {

		/*입력받기*/
		int N; cin >> N;
		int input1, input2;
		vector<pair<int, int>> move(N); //시작점(작은 거), 도착점(큰 거)

		for (int i = 0; i < N; i++) {
			cin >> input1 >> input2;

			input1 = (input1 + 1) / 2;
			input2 = (input2 + 1) / 2;

			if (input1 > input2) {
				int temp = input1;
				input1 = input2;
				input2 = temp;
			}

			move[i] = { input1, input2 };
		}


		/*해결하기*/
		vector<pair<int, int>> temp; //겹쳐서 이번 턴에 안 되는, 남은 경로를 담을 임시 벡터.
		int cnt = 0;

		sort(move.begin(), move.end()); //시작점 기준 오름차순 정렬

		while (!move.empty()) {
			int end = move[0].second; //경로 중 제일 큰 도착점

			//move[0]를 옮길 거야.
			for (int i = 1; i < move.size(); i++) { //걔랑 같이 또 뭘 옮길 수 있지?
				if (end < move[i].first)
					end = move[i].second;
				else //겹쳐서 같이 옮길 수 없으면
					temp.push_back(move[i]); //temp에 해당 경로 추가
			}

			move.swap(temp);
			temp.clear();
			cnt++;
		}

		/*출력하기*/
		cout << cnt * 10 << "\n";
	}

	return 0;
}
