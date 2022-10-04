import sys
input = sys.stdin.readline

N = int(input())
    
# 재귀 시간 초과 :(
# answer = [10]
# def recur(temp, n, S):
#     if n==S:
#         answer[0]+=1
#         return
#     for i in range(1, 10):
#         if temp%10 <= i:
#             recur(temp*10+i, n+1, S)

# for s in range(2, N+1):
#     for i in range(1, 10):
#         recur(i, 1, s)
#     answer[0]%=10007

# print(answer[0])