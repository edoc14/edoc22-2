import sys

input = sys.stdin.readline
sys.setrecursionlimit(1000000)  # 모든 드드

res = []  # 팀에 속한 노드들을 저장한 배열
visited = {}  # 특정 노드가 방문되었는지를 확인하는 dictionary
nextNode = {}  # key = 현재 노트, value = 다음 노드 인 dictionary


def dfs(node):
    global res, visited, nextNode
    visited[node] = True  # 현재 노드를 방문했음을 기록
    path.append(node)  # 현재 노드를 지나쳤음을 경로에 기록
    next = nextNode[node]  # 다음 노드

    if visited[next]:  # 다음 노드를 이미 방문했을 경우
        if next in path:  # 지나온 경로에 다음 노드가 있다면 cycle이 생겼음을 의미
            res += path[path.index(next):]  # cycle이 생겼으므로 cycle 생긴 부분만 res에 추가
        return
    else:  # 다음 노드를 방문하지 않은 경우 cycle이 생기지 않은 것이기 때문에 탐색을 이어나감
        dfs(next)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        # input
        n = int(input())  # 정점 개수
        nextNode = {i: x for i, x in
                    zip(range(1, n + 1), map(int, input().split()))}
        visited = {i: False for i in range(1, n + 1)}
        res = []

        # search
        for node in range(1, n + 1):
            if not visited[node]:  # 방문하지 않은 노드들만 탐색
                path = []  # node를 시작으로 새로운 경로를 탐색
                dfs(node)

        # print answer
        print(n - len(res))
