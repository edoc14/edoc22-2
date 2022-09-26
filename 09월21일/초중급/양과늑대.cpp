#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//탐색 중 양의 최댓값(즉 answer)을 리턴함.
int dfs(int currNode, vector<int> nextNodes, int sheep, int wolf, int answer, vector<int> info, vector<vector<int>> tree) {
    if (info[currNode] == 0) //현재 노드가 양일 경우
        sheep++;

    if (info[currNode] == 1) {//현재 노드가 늑대인 경우
        if (wolf + 1 >= sheep) return answer; //늑대가 더 많으면 현재 최댓값 그대로 리턴.
        else wolf++;
    }

    //양 최댓값 갱신
    answer = max(answer, sheep);


    //currNode 및 nextNode 갱신
    for (int i = 0; i < nextNodes.size(); i++) {
        vector<int> new_nextNodes = nextNodes;
        new_nextNodes.erase(new_nextNodes.begin() + i); //인자(next.begin() + i) : 다음 currNode. 인접노드 배열에서 삭제

        for (int j = 0; j < tree[nextNodes[i]].size(); j++) { //갱신된 currNode의 인접노드 삽입
            new_nextNodes.push_back(tree[nextNodes[i]][j]);
        }
        answer = dfs(nextNodes[i], new_nextNodes, sheep, wolf, answer, info, tree);
    }

    return answer;
}


int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1; //

    //각 노드를 행으로, 각 노드와 인접한 노드들을 열로 갖는 2차원 벡터 트리 생성.
    int N = info.size();
    vector<vector<int>> tree(N);
    for (int i = 0; i < edges.size(); i++) {
        tree[edges[i][0]].push_back(edges[i][1]);
    }

    //dfs함수의 nextNodes[] 인자 초기화 (시작노드 0의 인접노드들 삽입)
    vector<int> nextNodes;
    for (int i = 0; i < tree[0].size(); i++) {
        nextNodes.push_back(tree[0][i]);
    }

    answer = dfs(0, nextNodes, 0, 0, answer, info, tree);
    cout << answer;

    return answer;
}