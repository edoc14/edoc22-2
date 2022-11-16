#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> arr;

//�������� �������� ������������ �����Ѵ�.
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    //�Է�
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a, b });
    }
    //�������� ����
    sort(arr.begin(), arr.end(), cmp);

    //now : ������ - �����ϴ� �� �ɸ��� �� = �����Ͽ� ������ ������ ���� ������ �����ؾ� �ϴ� ��
    int now = arr[0].second - arr[0].first;
    for (int i = 1; i < n; i++) {
        int d = arr[i].first, t = arr[i].second;
        //now���� ���� ������ �������� �۰ų� ������ ���� X, ó��ó�� now ����
        if (now >= t) {
            now = t - d;
        }
        //�ƴ� ��� now���� �����ϴ� �� �ɸ��� �ϸ�ŭ ���� ����
        else {
            now = now - d;
        }
    }
    //���
    cout << now;

    return 0;
}