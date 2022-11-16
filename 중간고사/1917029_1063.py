K, S, n = input().split()
alphabet = {'A':0, 'B':1, 'C':2, 'D':3, 'E':4, 'F':5, 'G':6, 'H':7}
move = {'R':[0, 1], 'L':[0, -1], 'B':[1, 0], 'T':[-1, 0], 
        'RT':[-1, 1], 'LT':[-1, -1], 'RB':[1, 1], 'LB':[1, -1]}
king_x, king_y = 8 - int(K[1]), alphabet[K[0]]
stone_x, stone_y = 8 - int(S[1]), alphabet[S[0]]
for i in range(int(n)):
    m = input()
    if king_x + move[m][0] == stone_x and king_y + move[m][1] == stone_y:
        if 0 <= stone_x + move[m][0] < 8 and 0 <= stone_y + move[m][1] < 8:
            stone_x, stone_y = stone_x + move[m][0], stone_y + move[m][1]
        else:
            continue
    if 0 <= king_x + move[m][0] < 8 and 0 <= king_y + move[m][1] < 8:
        king_x, king_y = king_x + move[m][0], king_y + move[m][1]
reverse_move = dict(map(reversed, alphabet.items()))
print(reverse_move[king_y] + str(8 - king_x))
print(reverse_move[stone_y] + str(8 - stone_x))
