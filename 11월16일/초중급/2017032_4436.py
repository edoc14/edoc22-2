import sys

input = sys.stdin.readline


def cal_k(n):
    cnt = 1
    nums = set()
    all = set([1, 2, 3, 4, 5, 6, 7, 8, 9, 0])
    while len(all.difference(nums)):
        nums = nums.union(set(map(int, list(str(cnt * n)))))
        cnt += 1
    return cnt - 1


if __name__ == '__main__':
    try:
        while True:
            n = int(input())
            print(cal_k(n))
    except:
        exit(0)
