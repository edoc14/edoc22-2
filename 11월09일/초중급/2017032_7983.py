import sys

input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    assignment = []

    for i in range(n):
        di, ti = map(int, input().split())
        assignment.append([di, ti])

    assignment = sorted(assignment, key=lambda x: x[1]) #과제 마감일 기준으로 sort 해주기

    startDay = assignment[0][1] - assignment[0][0]  #과제를 시작해야 하는 날짜
    temp = assignment[0][1] #과제를 다했을 때 되는 날짜
    for i in range(1, n):
        temp += assignment[i][0]
        if temp > assignment[i][1]: #과제를 완료한 날짜가 마감일보다 늦다면
            #시작 날짜를 앞당긴다
            startDay -= temp - assignment[i][1] 
            temp -= temp - assignment[i][1]
    print(startDay)
