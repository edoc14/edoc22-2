# https://jjangsungwon.tistory.com/4

import sys
input = sys.stdin.readline

N = int(input())
cost = []

for n in range(N):
    cost.append(list(map(int, input().split(' '))))
    
def dfs(start, next, value, visited):
    global min_value

    if len(visited) == N:
        if cost[next][start] != 0:
            min_value = min(min_value, value + cost[next][start])
        return

    for i in range(N):
        if cost[next][i] != 0 and i != start and i not in visited:
            visited.append(i)
            dfs(start, i, value + cost[next][i], visited)
            visited.pop()
            
min_value = sys.maxsize

for i in range(N):
    dfs(i, i, 0, [i])

print(min_value)