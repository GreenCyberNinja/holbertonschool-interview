#!/usr/bin/python3


import sys


boardcnt = 0


def CheckBoard(board, row, col):
    """checks if queens can't attack each other"""
    for c in range(col):
        if (board[row][c] == 'Q'):
            return False
    for r, c in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
        if (board[r][c] == 'Q'):
            return False
    for r, c in zip(range(row+1, len(board), 1), range(col-1, -1, -1)):
        if (board[r][c] == 'Q'):
            return False
    return True


def SetNqueens(board, col):
    """sets the queens on the board"""
    global boardcnt
    if (col >= len(board)):
        boardcnt += 1
        PrintBoard(board)
    else:
        for row in range(len(board)):
            board[row][col] = 'Q'
            if (CheckBoard(board, row, col)):
                SetNqueens(board, col + 1)
            board[row][col] = '.'


def PrintBoard(board):
    """prints current queen coordinates"""
    pos = []
    for row in range(len(board)):
        for grid in range(len(board[row])):
            if board[row][grid] == 'Q':
                pos.append([row, grid])
    print(pos)


def main():
    """put it all together now"""
    board = []
    if len(sys.argv) < 2:
        print("Usage: nqueens N")
        exit()
    try:
        N = int(sys.argv[1])
    except Exception:
        print('N must be a number')
        exit()
    if N < 4:
        print('N must be at least 4')
        exit()
    for i in range(N):
        row = ["."] * N
        board.append(row)
    SetNqueens(board, 0)


if __name__ == "__main__":
    main()
