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

    return 0;
}