from typing import List

tree = {}
maxSheep = 0


def dfs(node, wolf, sheep, nextNodes, visited, info):
    global maxSheep, tree

    visited[node] = True  # 현재 노드를 방문했음을 기록
    nextNodes.extend(tree[node])  # 현재 노드의 자식들을 갈 수 있는 노드 리스트에 추가

    # 동물 수 1 더하기
    if info[node] == 0:  # 양일 경우
        sheep += 1
    else:  # 늑대인 경우
        wolf += 1

    # 늑대가 양을 잡아먹는 경우
    if wolf == sheep:
        return

    # 가장 많은 양을 모을 수 있도록 업데이트
    maxSheep = max(sheep, maxSheep)

    # 갈 수 있는 노드 다 재귀적으로 탐색을 이어감
    for n in nextNodes:
        # 다음 노드가 n인 경우, 갈 수 있는 노드들 중에서 자기 자신 n과 이미 방문한 노드들 제외하여 nextNodes 다시 정의
        next = [node for node in nextNodes if node != n and not visited[node]]
        dfs(n, wolf, sheep, next, visited[:], info) 


def createTree(edges: List[List[int]], info):  # key: parent node, value: children of key parent node(list)
    global tree
    tree = {i: [] for i in range(len(info))}
    for edge in edges:
        par, child = edge[0], edge[1]
        tree[par].append(child)


def solution(info: List[int], edges: List[List[int]]):
    global tree

    ans = 0

    createTree(edges, info)  # 편리성을 위해 트리 형성
    visited = [False for _ in range(len(info))]  # visited: 방문한 노드 확인하기 위한 list
    dfs(0, 0, 0, [], visited, info)     # 탐색 시작

    ans = maxSheep
    return ans
