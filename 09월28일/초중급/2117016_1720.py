n=int(input())
DPline = [0]*32 
#DP는 중복 고려하지 않고, n개의 블록이 가질 수 있는 모든 경우의 수
DPline[1] = 1
DPline[2] = 3
#DP값을 이용하여 답을 도춣 할 예정이므로, n까지 dp를 구한다.
for i in range(3,n+1):
    DPline[i] = DPline[i-1]+2*DPline[i-2]
    #DP[i]는 마지막으로 블록이 1개짜리 블록일때(DP[i-1])와
    #마지막으로 추가된 블록이 2개짜리 블록인 경우 2가지(2*DP[i-2])의 합
if n>=3:
    if (n%2) :  
        R = DPline[(n-1)//2]
        print((DPline[n]-R)//2 + R)
    else : 
        R = DPline[n//2]+2*DPline[(n-2)//2]
        print((DPline[n]-R)//2 + R)
else: print(DPline[n])