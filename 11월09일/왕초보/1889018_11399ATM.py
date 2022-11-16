import sys
input = sys.stdin.readline

N = int(input())
people = list(map(int, input().split(' ')))

people.sort() # 짧은 순서대로 서면 최단 시간

ans = 0
for i in range(N):
    ans += sum(people[:i+1]) # 누적해서 합해서 더함
    
print(ans)