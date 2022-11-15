import sys

input = sys.stdin.readline

if __name__ == '__main__':
    k = int(input())
    info = []
    width = []
    height = []

    for _ in range(6):
        dir, length = map(int, input().split())
        info.append(length)
        if dir > 2:
            height.append(length)
        else:
            width.append(length)

    big_square = max(width) * max(height)
    max_width_index = info.index(max(width))
    max_height_index = info.index(max(height))
    small_square = abs(info[(max_width_index - 1) % 6] - info[(max_width_index + 1) % 6]) * abs(
        info[(max_height_index - 1) % 6] - info[(max_height_index + 1) % 6])
    area = big_square - small_square
    print(area * k)
