#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



//x보다 가까우면 더 비쌈
//x보다 싸면 더 멀다
int main() {
	int n, p1, p2, cnt;
	vector<pair<int, int>>v;
	cin >> n;
	for(int i = 0; i<n;i++)
	{
		cin >> p1 >> p2;
		v.push_back(make_pair(p1, p2));
	}
	sort(v.begin(), v.end());
	cnt = n;
	
	for (int i = 1; i < n; i++) {
		if (v[i - 1].first < v[i].first && v[i - 1].second <= v[i].second) {
			v.erase(v.begin() + i);
			i--;
			n--;
			cnt--;
			continue;
		}
		else if (v[i - 1].first == v[i].first && v[i - 1].second < v[i].second) {
			v.erase(v.begin() + i);
			i--;
			n--;
			cnt--;
			continue;
		}
	}
	cout << cnt;

	return 0;
}