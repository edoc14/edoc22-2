import sys
from itertools import combinations

input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    a = []
    for i in range(1, 11):
        for c in combinations(range(0, 10), i):
            c = list(c)
            c.sort(reverse=True)
            a.append(int("".join(map(str, c))))
    a.sort()
    try:
        print(a[n])
    except:
        print(-1)