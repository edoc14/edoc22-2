#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N; //input

string cur;
int idx;
bool finish = false;

int ans;

int findK(int n) {
	vector<bool> check(10, false);
	finish = false;
	int k = 1;
	int current = n;

	while (finish == false) {
		//cout << "k : " << k << endl;
		current = n * k;
		cur = to_string(current);
		//cout << "cur : " << cur << endl;

		for (int i = 0; i < cur.size(); i++) {
			idx = (int)(cur[i]-'0');
			//cout << "idx : " << idx << endl;
			check[idx] = true;
		}
		//cout << "stream finished" << endl;

		for (int i = 0; i < check.size(); i++) {
			if (check[i] == false && i!=check.size()) {
				k++;
				cur.clear();
				//cout << "next" << endl;
				break;
			}
			if (i == check.size()-1) {
				finish = true;
			}
		}
	}

	check.clear();
	//cout << "final k : " << k;
	return k;
}

int main() {
	while (true) {
		cin >> N;
		ans = findK(N);
		
		cout << ans << endl;
	}
	return 0;
}