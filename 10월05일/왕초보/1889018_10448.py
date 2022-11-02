# https://www.acmicpc.net/problem/10448

import sys
input = sys.stdin.readline

T = int(input())

for t in range(T):
    K = int(input())
    flag = False
    for i in range(1, K):
        if flag:
            break
        for j in range(1, K):
            if flag:
                break
            for k in range(1, K):
                if (i*(i+1)+j*(j+1)+k*(k+1))==2*K:
                    flag = True
                    break
    if flag:
        print(1)
    else:
        print(0)