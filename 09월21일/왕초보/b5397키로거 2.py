import sys
input = sys.stdin.readline

N = int(input())

for n in range(N):
    passwd = input().rstrip()
    answer = [] # 마우스 기준 오른쪽 스택
    temp = [] # 마우스 기준 왼쪽 스택
    for p in passwd:
        if p=='<': # 마우스 왼쪽에 있던 문자를 오른쪽으로 옮김
            if len(answer):
                temp.append(answer.pop()) 
        elif p=='>': # 마우스 오른쪽에 있던 문자를 왼쪽으로 옮김
            if len(temp):
                answer.append(temp.pop())
        elif p=='-': # 마우스 왼쪽의 문자를 지움(answer)
            if len(answer):
                answer.pop()
        else:
            answer.append(p)
    if len(temp): # 마우스 왼쪽과 오른쪽 문자를 모두 합침
        answer.extend(reversed(temp)) # 거꾸로 돌려줘야 함
    print(''.join(answer))