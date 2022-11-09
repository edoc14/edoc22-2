import sys
n=int(sys.stdin.readline())
li=[]
line=[]
for i in range(6):
    a,b = map(int,sys.stdin.readline().split())
    li.append([a,b])
for i in range(6):
    li.append(li[i])
for i in range(9):
    if (li[i][0] == li[i+2][0]) and (li[i+1][0] == li[i+3][0]):
        ans=i
        line.append(li[i+1][0])
        line.append(li[i+2][0])
        x=li[i+2][1]
        y=li[i+1][1]
        break
tmp=[1,2,3,4]
farm=1
tmp.remove(line[0])
tmp.remove(line[1])
for i in range(6):
    if li[i][0]==tmp[0] or li[i][0]==tmp[1]:
        farm*=li[i][1]
print((farm-x*y)*n)
