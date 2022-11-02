import sys
input = sys.stdin.readline 

K = int(input())

for _ in range(6):
    direct, distance = map(int, input().split(' '))
    
print(ans*K)