#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 1000000000
#define MOD 1000000007
#define NUM 100010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int T, N, psum[210];

void init() {
	cin >> T;
	while(T--) {
		memset(psum, 0, sizeof(psum));
		cin >> N;
		for(int i=0; i<N; i++) { //그냥 다 계산^^
			int x, y;
			cin >> x >> y;
			x--, y--;
			x /= 2, y /= 2;
			if(x > y) swap(x, y);
			for(int j=x; j<=y; j++) psum[j]++;
		}
		for(int i=0; i<=200; i++) {
			psum[i] = max(psum[i], psum[i-1]);
		}
		cout << psum[200] * 10 << '\n'; //가장 큰 값에 10 곱해서 출력
	}
}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}