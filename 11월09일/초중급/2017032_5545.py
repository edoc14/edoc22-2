import sys

input = sys.stdin.readline

def calPizzaCalPerWon(toppings_cal, a_cost, b_cost, c_cal):
    cost = a_cost + b_cost * len(toppings_cal)
    cal = c_cal + sum(toppings_cal)
    return cal / cost


if __name__ == '__main__':
    #input
    n = int(input())
    a_cost, b_cost = map(int, input().split())
    c_cal = int(input())
    topping_cal = []
    for _ in range(n):
        topping_cal.append(int(input()))

    #값이 크게 나오게 하려면 calorie가 큰 것부터 더해야 하기 떄문에 sort해줌
    topping_cal.sort(reverse=True)

    max = 0
    for i in range(n + 1):  #topping 개수가 0 ~ n일 떄의 모든 경우의 수 고려
        val = calPizzaCalPerWon(topping_cal, a_cost, b_cost, c_cal)
        max = val if val > max else max #기존 max 값보다 클 경우에만 max 값 업데이트해주기
        try:
            topping_cal.pop()   #topping 개수를 1개씩 지우기 (calorie가 가장 작은 거)
        except:
            continue
    print(int(max)) #소수점 버린 형태로 print해주기
