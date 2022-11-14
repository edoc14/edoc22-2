# https://ryu-e.tistory.com/59 참조
# https://www.acmicpc.net/problem/1038

import sys
from itertools import combinations

input = sys.stdin.readline

decline = []
N = int(input())

for i in range(1, 11):
    for comb in combinations(range(0, 10), i):
        comb = list(comb)
        comb.sort(reverse=True)
        decline.append(int("".join(map(str, comb))))

decline.sort()

try:
    print(decline[N])
except:
    print(-1)