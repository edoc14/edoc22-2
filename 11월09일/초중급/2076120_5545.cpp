/*
�ְ��� ���� (���� 5545)
���� ������ ���ؾ���..
�׷��� �� ����/������ ���� ���� ���� �����Ѵ�.
������ �Ȱ��� ������ �ٸ�
���� ���� /A+B*k �̰��� �ִ��� ���ؾ���..
����� ����Ʈ. ���� �ϳ��� �� �ΰ��� �� ������ �� �̷������� �� �ؾ���..
*/
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int N;   // ���� ����
    int A;   // ���� ����
    int B;   // ���� ����
    int C;   // ���� ����
    int D[100];   // ���� ����
    int value;   //�� ����
    int price;   //�� ����
    int temp;   // ����

    cin >> N;
    cin >> A;
    cin >> B;
    cin >> C;
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
        int j = i;
        while (j != 0 && D[j] > D[j - 1]) {   // �������� ����
            temp = D[j - 1];
            D[j - 1] = D[j];
            D[j] = temp;
            j--;
        }
    }
    value = C;
    price = A;
    for (int i = 0; i < N; ++i) {
        if (C / A < D[i] / B) {
            C += D[i];
            A += B;
        }
    }
    cout << C / A;

    return 0;
}