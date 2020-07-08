from __future__ import print_function
import os

while True:
    def clear():
        os.system('cls')

    # board = [x for x in '_'*9]
    board = [x for x in range(1, 10)]

    def display_board():
        for i in range(0, 9, 3):
            print(board[i], board[i + 1], board[i + 2], sep=" | ")

    display_board()

    def check_win():
        for i in range(0, 9, 3):
            if board[i] == board[i + 1] == board[i + 2]:
                return board[i]
        for i in range(3):
            if board[i] == board[i + 3] == board[i + 6]:
                return board[i]
        if board[0] == board[4] == board[8]:
            return board[0]
        if board[2] == board[4] == board[6]:
            return board[2]

    pos_range = [i for i in range(1, 10)]

    x = 0
    while x <= 8:
        try:
            if x % 2 == 0:
                print("Turn of, x")
            else:
                print("Turn of, O")
            pos = int(input('Enter your position (1-9) ')) - 1
            clear()
            if (pos + 1) in pos_range:
                if board[pos] == 'X' or board[pos] == 'O':
                    print('Already in use Ha ha!\n')
                else:
                    if x % 2 == 0:
                        board[pos] = 'X'
                    else:
                        board[pos] = 'O'
                    x += 1
            else:
                print('You are out of the range fool!\n')
        except NameError:
            clear()
            print('What you are trying to do fool!\n')
        display_board()
        check_winner = check_win()
        if check_winner:
            print('you are winner ', check_winner)
            break
    if not check_win():
        print("This tie Good Game")
    os.system("pause & cls")
    print("\nLet's Play again!\n")
