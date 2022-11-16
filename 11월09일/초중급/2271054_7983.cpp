#pragma warning (disable:4996)
#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> p[1000009];
int startdate = 0;

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		p[i].first = b;
		p[i].second = a;
	}

	sort(p, p + n, greater<>());
	startdate = p[0].first + 1;
	///check///
	//printf("%d\n", startdate);
	//for (int i = 0; i < n; i++) {
	//	printf("%d %d\n", p[i].first, p[i].second);
	//}

	for (int i = 0; i < n; i++) {
		int duedate = p[i].first;
		int time = p[i].second;
		if (startdate > duedate) {
			startdate = duedate - time + 1;
		}
		else {
			//startdate--;
			startdate = startdate - time;
		}
	}

	printf("%d", startdate - 1);

	return 0;
}


// 
// 13 1
// 10 3
//  8 2
//// 
//// 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 
//// 0 0 0 0 0 1 1 
//// 0 0 0 0 0 0 0 0 0 0 0 0 1   
//// 0 0 0 0 0 0 0 1 1 1          
//// 
//// 
