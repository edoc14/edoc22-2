from sys import stdin
A, B, C = map(int,stdin.readline().split())

if B >= C:
    print(-1)
else:
    print(int(A//(C-B)+1))
