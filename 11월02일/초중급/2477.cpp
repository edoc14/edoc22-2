#include <iostream>
#include <vector>
using namespace std;

//1:�� 2:�� 3:�� 4:��
int K; //1m^2�� ���� ���� (1 <= K <= 20)
int edge[7][7]; //(����, ����)
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