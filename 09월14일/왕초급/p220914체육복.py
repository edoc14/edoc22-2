def solution(n, lost, reserve):
    student = [False for i in range(n+2)]
    
    for r in reserve:
        student[r] = True
    
    lost.sort()
    reserve.sort()
    
    answer = n-len(lost)
    
    for l in lost:
        temp = 0
        if student[l-1]:
            temp = l-1
        elif student[l]:
            temp = l
        elif student[l+1]:
            temp = l+1
        if temp!=0:
            student[temp] = False
            answer+=1
        
    return answer