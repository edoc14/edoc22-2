#include <iostream>
#include <vector>
using namespace std;

int N; //1<=N<=100 //���� ���� �� //���� ���� 1������ or 0��
int A, B; //1<=A,B<=1000 //A: ���� ����, B: ���� ����
int C; //���� ����
vector<int> D; //���κ� ���� (�� N��) 

//���� ���� = A + B * k(������ ���� ����)
//���� ���� = C + D * k


int main() {
	cin >> N >> A >> B >> C;
	for (int i = 1; i <= N; i++) cin >> D[i];

	

	int price = A + ; //�ְ��� ���� ����
	int cal = C + ; //�ְ��� ���� ����
	int result = cal / price; //'�ְ��� ����'�� 1���� ����
	cout << result;
	return 0;
}