import sys 
sys.setrecursionlimit(2000000)

def dfs(x):
    global ans
    visited[x] = True #방문했다고 표시
    done.append(x) #done에 넣어줌
    number = numbers[x] # 다음 인덱스 저장
    
    if visited[number]: #다음 인덱스 확인할 수 있을 때
        if number in done: #조 편성 완료일 때 조 이루는 곳만 체크하고 종료
            ans += done[done.index(number):] #ans에 팀 이루는 사람들 쭉 넣기
        return
    else: # 아니면 계속 돌림
        dfs(number)


T = int(input())

for _ in range(T):
    
    N = int(input())

    ans = [] #팀 이루는 사람 넣기
    visited = [True]+[False]*N #사이클 내에서 방문 여부
    numbers = [0] + list(map(int, input().split()))
    
    
    for i in range(1, N+1):
        if not visited[i]:#방문안한 곳은 
            done = []
            dfs(i)#체크!
            
    print(N - len(ans)) #팀에 없는 사람 수