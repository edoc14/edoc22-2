def solution(operations):
    answer = []
    
    for op in operations:
        if op=="D 1" and len(answer):
            answer.pop(0)
        elif op=="D -1" and len(answer):
            answer.pop()
        else:
            answer.append(int(op[1:]))
            answer.sort(reverse = True)
    
    if not len(answer):
        answer = [0, 0]
    else:
        answer = [answer[0], answer[-1]]
    
    return answer