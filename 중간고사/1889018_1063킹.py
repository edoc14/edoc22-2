import sys
input = sys.stdin.readline
# 문제 설명이 참 그지같다
# https://www.acmicpc.net/problem/1063
# * 연산 사용하면 얕은 복사 되어, chess[0][0] 바꾸면 모든 열[0]이 바뀜. 새로운 사실

king, stone, N = map(str, input().split(' '))
King = [(ord(king[0])-ord('A')), int(king[1])-1]
Stone = [(ord(stone[0])-ord('A')), (int(stone[1])-1)]

# 움직이는 좌표
moveRL = [1, -1, 0, 0, 1, -1, 1, -1]
moveBT = [0, 0, -1, 1, 1 , 1, -1, -1]
move = {'R': 0, 'L': 1, 'B': 2, 'T': 3, 'RT': 4, 'LT': 5, 'RB': 6, 'LB': 7} 
# 움직이는 좌표 리스트 상의 해당 번호를 딕셔너리로 매핑

for n in range(int(N)):
    moveRLBT = input().rstrip()
    temp = King.copy()
    if 0<=King[0]+moveRL[move[moveRLBT]]<8 and 0<=King[1]+moveBT[move[moveRLBT]]<8:
        King[0] += moveRL[move[moveRLBT]]
        King[1] += moveBT[move[moveRLBT]]
    if King==Stone: # King이랑 Stone이랑 부딪히는 경우 Stone도 이동
        if 0<=Stone[0]+moveRL[move[moveRLBT]]<8 and 0<=Stone[1]+moveBT[move[moveRLBT]]<8:
            Stone[0] += moveRL[move[moveRLBT]]
            Stone[1] += moveBT[move[moveRLBT]]
        else: # 부딪혔는데 Stone이 바깥에 나가는 경우 원상 복귀
            King = temp
    
        
print(chr(King[0]+ord('A'))+str(King[1]+1))
print(chr(Stone[0]+ord('A'))+str(Stone[1]+1))
    
