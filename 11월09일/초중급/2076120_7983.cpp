/*
* ���� 7983 �����Ұž�
* �Է� ���� 
* n => ���� ����
* i => ���� index , d => ������ �ɸ��� �� �� 
* t => ������ due date
* �ִ� ��ĥ���� �� �� �ִ��� ���ϴ� �˰���
* // ��� ���
* 1. ���� ���� �Է� �ޱ� [*]
* 2. ���� ���� ��ŭ d�� t �Է� �ޱ� [*]
* -- ���� -- 
* ���� due date�� ����� ��: �� �� �ִ� ��¥�� ���� ���� ����?
* ----------
* ��Ÿ�� ���� �߻�! 
* ���� ���ؾ� �ϴ� �Ⱓ�� ��ġ�� ��ƾ��ϴ� �� ������ ��ġ�� �� ����� ��.
* 10�� 4�� / 8�� 3�� �̸� => 7,8,9,10/ 5,6,7.. 
* �׷��� ���ؾ��ϴ� ���� �����صΰ�?  ��ġ�°� ������ playPersign�� -1���ִ� ����.
* 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_SIZE 1000000

int* getInput(int n){
	int playPerAssign[MAX_SIZE];
	int input[2] = {0, };
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> input[0] >> input[1];
		playPerAssign[i] = input[1]- input[0];
		for (int j = input[2]; j < input[1]; j++) {
			if (v.end() == find(v.begin(), v.end(), j)) {
				playPerAssign[i]--;
				v.push_back(j - 1);

			}
			v.push_back(j);
		}
	}
	return min_element(begin(playPerAssign), end(playPerAssign));
}
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> day;
	int* playDay = getInput(n);
	cout << &playDay;
}