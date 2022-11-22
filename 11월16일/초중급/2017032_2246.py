import sys

input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    condos = {}

    d_candidates = set()  # 1번째 조건에만 부합하는 후보들
    c_candidates = set()  # 2번쨰 조건에만 부합하는 후보들

    for _ in range(n):
        d, c = map(int, input().split())
        try:
            condos[d] = min(condos[d], c)  # 2번쨰 조건에 의해 만약 거리가 같은 콘도가 있다면, 가장 숙박비가 싼 콘도만 후보가 될 수 있다.
        except KeyError:
            condos[d] = c

    d_condos = sorted(condos.items(), key=lambda x: x[0])  # 거리 중심으로 정렬한 콘도 배열
    c_condos = sorted(condos.items(), key=lambda x: x[1])  # 숙박비 중심으로 정렬한 콘도 배열

    minCost, minDistance = 100000, 100000
    for condo in d_condos:  # 1번째 조건에 부합하는 후보들을 찾는 for문
        if condo[1] < minCost:
            d_candidates.add(condo)
        minCost = min(condo[1], minCost)
    for condo in c_condos:  # 2번째 조건에 부합하는 후보들을 찾는 for문
        if condo[0] < minDistance:
            c_candidates.add(condo)
        minDistance = min(condo[0], minDistance)

    print(len(d_candidates.intersection(c_candidates)))  # 1번째 & 2번쨰 조건 부합하는 후보들의 숫자 출력
