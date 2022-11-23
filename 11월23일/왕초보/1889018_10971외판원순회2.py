import sys
input = sys.stdin.readline

N = int(input())
cost = []

for n in range(N):
    cost.append(list(map(int, input().split(' '))))

for n in range(N):
    visited = [False for n in range(N)]
    visited[n]=True
    
def recur(N, visited, cost):
    for n in range(N):
        if not visited[n]:
             visited[n] = True
             