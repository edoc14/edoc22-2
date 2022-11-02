import sys

input = sys.stdin.readline


def valid(row, col):
    if 'A' <= col <= 'H' and 1 <= int(row) <= 8:
        return True
    return False


if __name__ == '__main__':
    king_pos, rock_pos, n = input().split()
    king_col, king_row, rock_col, rock_row = king_pos[0], int(king_pos[1]), rock_pos[0], int(rock_pos[1])
    for i in range(int(n)):
        op = input().rstrip()
        temp = [king_col, king_row, rock_col, rock_row]
        if op == "R":
            king_col = chr(ord(king_col) + 1)
        elif op == "L":
            king_col = chr(ord(king_col) - 1)
        elif op == "B":
            king_row -= 1
        elif op == "T":
            king_row += 1
        elif op == "RT":
            king_col = chr(ord(king_col) + 1)
            king_row += 1
        elif op == "LT":
            king_col = chr(ord(king_col) - 1)
            king_row += 1
        elif op == "RB":
            king_col = chr(ord(king_col) + 1)
            king_row -= 1
        elif op == "LB":
            king_col = chr(ord(king_col) - 1)
            king_row -= 1
        if not valid(king_row, king_col):
            king_col, king_row = temp[0], temp[1]
            continue
        if king_row == rock_row and king_col == rock_col:
            rock_row = rock_row + (king_row - temp[1])
            rock_col = chr(ord(rock_col) + (ord(king_col) - ord(temp[0])))
        if not valid(rock_row, rock_col):
            rock_col, rock_row = temp[2], temp[3]
            king_col, king_row = temp[0], temp[1]
    print(king_col + str(king_row))
    print(rock_col + str(rock_row))
