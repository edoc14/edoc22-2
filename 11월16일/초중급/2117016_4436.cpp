#include <iostream>

using namespace std;
bool check(long long ans, int checknum[]) {
	while(ans>9){
		checknum[ans % 10]++;
		ans /= 10;
	}
	checknum[ans]++;
	for (int i = 0; i < 10; i++) {
		if (checknum[i] ==0)
			return false;
	}
	return true;
}


int main() {
	long long ans = 0; 
	long long n;
	while (cin>>n) {
		int checknum[10] = { 0, };
		long long k = 0;
		while (1) {
			k++;
			ans = n * k;
			if (check(ans, checknum)==true) {
				cout << k << "\n";
				break;
			}
		}
	}
	return 0;
}