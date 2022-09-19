def solution(n, lost, reserve):
    checklist= [ 0 for _ in range(n)] #전체 학생 수 만큼의 빈칸

     # 자기가 체육복 안 가져온 경우
    reserve_del = set(reserve)-set(lost) 
    lost_del = set(lost)-set(reserve) 

    result = n - len(lost_del) #현재 체육복 있는 사람
            
    for cha in lost_del:
        if cha + 1 in reserve_del:
            checklist[cha-1] += 1 # 이 번호의 친구의 체육복 빌릴 수 있는 가능성 +1
        if cha - 1 in reserve_del:
            checklist[cha-1] += 1 # +2

    #빌릴 가능성 높이기
    for i in range(n):
        if checklist[i] >= 1: # (번호는 i+1인 상태)
            if i in reserve_del:
                result += 1
                reserve_del.remove(i)
            elif i+2 in reserve_del:
                result += 1
                reserve_del.remove(i+2)
            
    return result
