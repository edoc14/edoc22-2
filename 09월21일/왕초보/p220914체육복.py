def solution(n, lost, reserve):
    only = set(lost)&set(reserve) # 여분 체육복 있는데 잃어버린 애
    lost = list(set(lost)-only) # 순수 잃어버린 애
    reserve = list(set(reserve)-only) # 순수 남는 체육복 있는 애
    
    answer = n - len(lost)
    
    for l in lost: 
        for i, r in enumerate(reserve):
            if l-1==r: # greedy로 여분이 있는 애가 전 번호 애한테 우선 빌려줌
                answer+=1
                reserve.pop(i) # 빌려준 경우 제외
            elif l+1==r:
                answer+=1
                reserve.pop(i) # 빌려준 경우 제외
    
    return answer