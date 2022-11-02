#include <iostream>
#include <vector>
using namespace std;

//1:동 2:서 3:남 4:북
int K; //1m^2당 참외 개수 (1 <= K <= 20)
int edge[7][7]; //(방향, 길이)
int field[1001][1001];

int main() {
	cin >> K;
	for (int i = 1; i <= 6; i++) {
		cin >> edge[i][1] >> edge[i][2];
	}
	
	int current_x, current_y;
	for (int i = 1; i <= 6; i++) {
		if (edge[i][1] == 1) {
			while (current_x--) {
				
			}
		}
		if (edge[i][1] == 2) {

		}
		if (edge[i][1] == 3) {

		}
		if (edge[i][1] == 4) {

		}
	}
	


}