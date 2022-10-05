import sys
from collections import deque

input = sys.stdin.readline


def bfs(fiber, current, start, m, n):
    q = deque([start])
    while q:
        node, r, c = q.popleft()
        if not current[r][c]:
            if node == 0:
                current[r][c] = True
                for n_r, n_c in zip((r - 1, r + 1, r, r), (c, c, c - 1, c + 1)):  # 상화좌우
                    if 0 <= n_r < m and 0 <= n_c < n:
                        q.append((fiber[n_r][n_c], n_r, n_c))

if __name__ == '__main__':
    m, n = map(int, input().split())
    fiber = []
    current = []
    for _ in range(m):
        fiber.append(list(map(int, input().rstrip())))
        current.append([False for _ in range(n)])

    for out, c in zip(fiber[0], range(n)):
        if out == 0:
            bfs(fiber, current, (out, 0, c), m, n)

    for inner, c in zip(fiber[m - 1], range(n)):
        if inner == 0 and current[m - 1][c]:
            print("YES")
            exit(0)
    print("NO")
