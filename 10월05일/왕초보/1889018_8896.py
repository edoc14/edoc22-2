import sys
input = sys.stdin.readline

T = int(input())

for t in range(T):
    N = int(input())
    robots = list()
    for n in range(N):
        robots.append(input().rstrip())
    K = len(robots[0])
    survivor = [True]*N

    for k in range(K):
        round = set()
        for n in range(N):
            if survivor[n]:
                round.add(robots[n][k])
        if len(round)==2:
            failure = 'R'
            if round == set(['R', 'S']):
                failure = 'S'
            elif round == set(['S', 'P']):
                failure = 'P'
            for n in range(N):
                if robots[n][k]==failure:
                    survivor[n] = False
                        
    if survivor.count(True) > 1:
        print(0)
    else:
        print(survivor.index(True)+1)