import sys
li=[]
n=int(sys.stdin.readline())
ans=[]
for i in range(n):
    tmp=list(map(int, sys.stdin.readline().split()))
    li.append(tmp)
def dfs(i, start, cost,note):
    global ans
    if note.count(1)==n:
        if li[i][start]!=0:
            ans.append(cost+li[i][start])
        return
    for j in range(n):
        if note[j]==0 and li[i][j] != 0:
            cost+=li[i][j]
            note[j]=1
            dfs(j,start, cost,note)
            note[j]=0

for i in range(n):
    cost=0
    note=[0]*n
    note[i]=1
    dfs(i,i, cost, note)
print(min(ans))
