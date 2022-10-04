
def findparent(edges, info, i):
    global wolf
    global ans
    #print("e",edges[i])
    j=edges[i][1]
    if info[j] == 0:
        ans+=1
    else:
        wolf+=1
    if edges[i][0] != 0:
        findparent(edges,info,edges[i][0]-1)
    else:
        ans+=1
        return
    #print("e",edges[i][0])
def solution(info, edges):
    global wolf
    global ans
    cnt=[0]*len(info)
    answer = 0
    edges.sort(key = lambda x:x[1])
    print("edges",edges)
    for i in range(1,len(info)):
        print("출력",i)
        ans=0
        wolf=0
        findparent(edges,info, i-1)
        print("ans",ans,wolf)
    return answer
info = [0,0,1,1,1,0,1,0,1,0,1,1]
edges = [[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]
solution(info, edges)
