#include <iostream>
#include <vector>
using namespace std;

typedef struct edge {
	int direction; //1:�� 2:�� 3:�� 4:��
	int length; // 1 <= length <= 500
	edge* front;
	edge* back;
} edge; //�־����� �������� �� ���� double linked list�� edge�� �����Ͽ�, �������� edge���� cycle�� �����Ѵ�. 
		//front�� back�� �̾��� �� ���� ����Ų��.

edge edges[7]; //edges[1]~[6]�� �������� �� ���� �����Ѵ�.

int K; //1m^2�� ���� ���� (1 <= K <= 20)
int area; //�� ����

int main() {
	cin >> K;
	for (int i = 1; i <= 6; i++) {
		cin >> edges[i].direction >> edges[i].length;
	}

	//�Էµ� ������ ���� �� ���� front�� back�� �����Ѵ�.
	for (int i = 1; i <= 6; i++) {
		if (i == 1) { //edges[1]�� front�� edges[6]�� ����Ų��.
			edges[i].front = &edges[6]; 
			edges[i].back = &edges[i + 1];
		}
		else if (i == 6) {//edges[6]�� back�� edges[1]�� ����Ų��.
			edges[i].front = &edges[i-1];
			edges[i].back = &edges[1];
		}

		else { //������ ������ front�� �ٷ� ��, back�� �ٷ� �޼����� edge�̴�.
			edges[i].front = &edges[i - 1];
			edges[i].back = &edges[i + 1];
		}
	}

	//���� ����� ������������ ���̴� ���� ���� ������ �� �� ���޾Ƽ� ��Ÿ����.
		//ex. �����Է�1�� ��� 4 2 3 1 3 1 -> 3 1 �� �����ؼ� �� �� ��Ÿ��.
		//ex2.				 3 1 4 2 3 1 -> �������� double linked list�� ������ cycle�̱� ������ ���� �����ϰ� 3 1�� �����ؼ� �� �� ��Ÿ���ٰ� �� �� �ִ�. 
	//���� ������ ������ ���̸� ���ϸ� ���� �������� ���δ� ��ü �簢���� ���� �� ���� ���̰� �ȴ�.
	//�׸��� ���ܵǴ� �簢���� ���
	//edges[i]�� front���� back���� ������ ����, edges[i]���� edges[i]->back->back���� ������ ���ٸ�, edges[i]�� edges[i].back�� ���ܵǴ� �簢���� �� ���� �ȴ�. 
		//ex. 4 2 3 1 3 1 �� 4 2 3a 1a 3b 1b �� ��Ÿ�� ��, ���ܵǴ� �簢���� ������ (1a���� ����) x (3b���� ����)�̴�.

	int x, y; //��ü �簢���� �� �� ����
	int z, w; //���ܵǴ� �簢���� �� �� ����
		   	  //�� �������� ������ x*y - z*w

	for (int i = 1; i <= 6; i++) { //���ܵǴ� �簢���� ���� �Ǵ� ������ �����ϴ� edges[i] Ž��
		if (edges[i].direction == edges[i].back->back->direction && edges[i].front->direction == edges[i].back->direction) {
			x = edges[i].length + edges[i].back->back->length;
			y = edges[i].front->length + edges[i].back->length;

			z = edges[i].length;
			w = edges[i].back->length;
			
			area = x * y - z * w;
			break;
		}
	}

	int result = K * area; //�翡�� �ڶ�� ������ �� ���� (����� ����)

	cout << result;
	return 0;
}