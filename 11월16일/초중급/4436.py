import sys
input=sys.stdin.readline
while(1):
    try:
        num=[]
        n=input().rstrip()
        nxt=n
        k=1
        while(len(num)<10):
            nxt=list(nxt)
            for tmp in nxt:
                if tmp not in num:
                    num.append(tmp)
            k+=1
            nxt=str(int(n)*k)
        if(len(num)==10):
            print(k-1)
    except:
        break
