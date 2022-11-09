from sys import stdin
K = int(stdin.readline()) # 참외면적당개수
Nlist = [list(map(int, stdin.readline().split())) for _ in range(6)]
rowBig = 0
colBig = 0
rowindex = 0
colindex = 0

for i in range(6):
    if Nlist[i][0] == 1 or  Nlist[i][0] == 2: #가로 1.2
        if Nlist[i][1] > rowBig:
            rowBig = Nlist[i][1]
            rowindex = i
    else: #세로 3.4
        if Nlist[i][1] > colBig:
            colBig = Nlist[i][1]
            colindex = i

colreal = abs(Nlist[(colindex-1)%6][1]-Nlist[(colindex+1)%6][1])
rowreal = abs(Nlist[(rowindex-1)%6][1]-Nlist[(rowindex+1)%6][1])

print(((colBig*rowBig)-(colreal*rowreal))*K)
