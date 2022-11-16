import sys
while(True):
    try:
        ans=1
        num=['0','1','2','3','4','5','6','7','8','9']
        n=int(sys.stdin.readline())
        plus=n
        while (len(num)!=0):
            #print("n",n)
            #print("num",num)
            for i in str(n):
                if i in num:
                    num.remove(i)
            ans+=1
            n+=plus
        print(ans-1)
    except:
        break
