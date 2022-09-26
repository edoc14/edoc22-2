#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Ž�� �� ���� �ִ�(�� answer)�� ������.
int dfs(int currNode, vector<int> nextNodes, int sheep, int wolf, int answer, vector<int> info, vector<vector<int>> tree) {
    if (info[currNode] == 0) //���� ��尡 ���� ���
        sheep++;

    if (info[currNode] == 1) {//���� ��尡 ������ ���
        if (wolf + 1 >= sheep) return answer; //���밡 �� ������ ���� �ִ� �״�� ����.
        else wolf++;
    }

    //�� �ִ� ����
    answer = max(answer, sheep);


    //currNode �� nextNode ����
    for (int i = 0; i < nextNodes.size(); i++) {
        vector<int> new_nextNodes = nextNodes;
        new_nextNodes.erase(new_nextNodes.begin() + i); //����(next.begin() + i) : ���� currNode. ������� �迭���� ����

        for (int j = 0; j < tree[nextNodes[i]].size(); j++) { //���ŵ� currNode�� ������� ����
            new_nextNodes.push_back(tree[nextNodes[i]][j]);
        }
        answer = dfs(nextNodes[i], new_nextNodes, sheep, wolf, answer, info, tree);
    }

    return answer;
}


int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1; //

    //�� ��带 ������, �� ���� ������ ������ ���� ���� 2���� ���� Ʈ�� ����.
    int N = info.size();
    vector<vector<int>> tree(N);
    for (int i = 0; i < edges.size(); i++) {
        tree[edges[i][0]].push_back(edges[i][1]);
    }

    //dfs�Լ��� nextNodes[] ���� �ʱ�ȭ (���۳�� 0�� �������� ����)
    vector<int> nextNodes;
    for (int i = 0; i < tree[0].size(); i++) {
        nextNodes.push_back(tree[0][i]);
    }

    answer = dfs(0, nextNodes, 0, 0, answer, info, tree);
    cout << answer;

    return answer;
}