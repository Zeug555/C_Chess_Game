/*
Author : Lïam LOTTE
Creation Date : 27/11/2023
Last Update : 28/11/2023
Title : main.c
*/

#include <stdio.h>
#include "board.h"
#include "move.h"

int main()
{
    int** board = boardInit();
    boardPrint(board);

    board[1][3] = HOLLOW;
    boardPrint(board);

    pieceMovement(board, 2, 0, 4, 2);
    boardPrint(board);

    pieceMovement(board, 4, 2, 0, 6);
    boardPrint(board);

    return 0;
}