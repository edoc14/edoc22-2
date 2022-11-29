# https://hongcoding.tistory.com/118

import sys
input = sys.stdin.readline

sudoku = []

for _ in range(9):
    sudoku.append(list(map(int, input().split(' '))))

zeros = list()

for i in range(9):
    for j in range(9):
        if sudoku[i][j] == 0 :
            zeros.append([i, j])

def row(x, num):
    for i in range(9):
        if sudoku[x][i] == num:
            return False
    return True

def col(y, num):
    for i in range(9):
        if sudoku[i][y] == num:
            return False
    return True

def square(x, y, num):
    x = x//3 * 3
    y = y//3 * 3
    for i in range(3):
        for j in range(3):
            if sudoku[x+i][y+j] == num:
                return False
    return True
 
def dfs(idx):
    if idx == len(zeros):
        for s_line in sudoku:
            for s in s_line:
                print(s, end=' ')
            print()
        exit(0)
    for i in range(1, 10):
        x = zeros[idx][0]
        y = zeros[idx][1]
        if row(x, i) and col(y, i) and square(x, y, i):
            sudoku[x][y] = i
            dfs(idx+1)
            sudoku[x][y] = 0

dfs(0)