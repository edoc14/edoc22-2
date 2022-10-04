import sys
n=int(sys.stdin.readline().rstrip())
for i in range(n):
    s1=[]#스택 앞 
    s2=[]#스택 뒤 
    s=str(sys.stdin.readline().rstrip())
    for j in s:
        if j == '<':
            if s1:
                s2.append(s1.pop())
        elif j == '>':
            if s2:
                s1.append(s2.pop())
        elif j == '-':
            if s1:
                s1.pop()
        else:
            s1.append(j)
    print(''.join(s1)+''.join(s2[::-1]))
