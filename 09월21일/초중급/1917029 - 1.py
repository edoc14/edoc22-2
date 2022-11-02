def solution(info, edges):
    visited = [0] * len(info)
    visited[0] = 1
    ans=[]
    def dfs(sheep, wolf, visited):
        if sheep > wolf:
            ans.append(sheep)
        else:
            return
        for i in edges:
            if visited[i[0]]==1 and visited[i[1]]==0:
                newVisited=visited.copy()
                newVisited[i[1]]=1
                if info[i[1]]==1:
                    dfs(sheep,wolf+1,newVisited)
                else:
                    dfs(sheep+1,wolf,newVisited)
    dfs(1,0,visited)

    return (max(ans))
