/*
Author: Lïam LOTTE
Creation Date: 27/11/2023
Last Update: 27/11/2023
Title: init.c
*/

#include "board.h"

int** boardInit()
{
    // Memory Allocation
    int** columnTab = malloc(8 * sizeof(int*)); 
    for (int i = 0; i < 8; i++)
    {
        columnTab[i] = malloc(8 * sizeof(int)); 
    }

    // Black Pawn placement
    for (int i = 0; i<8; i++)
    {
        columnTab[1][i] = B_PAWN;
    }

    // Others black pieces placement
    columnTab[0][0] = B_ROOK;
    columnTab[0][7] = B_ROOK;
    columnTab[0][1] = B_KNIGHT;
    columnTab[0][6] = B_KNIGHT;
    columnTab[0][2] = B_BISHOP;
    columnTab[0][5] = B_BISHOP;
    columnTab[0][3] = B_QUEEN;
    columnTab[0][4] = B_KING;

    // White Pawn placement
    for (int i = 0; i<8; i++)
    {
        columnTab[6][i] = W_PAWN;
    }

    // Others black pieces placement
    columnTab[7][0] = W_ROOK;
    columnTab[7][7] = W_ROOK;
    columnTab[7][1] = W_KNIGHT;
    columnTab[7][6] = W_KNIGHT;
    columnTab[7][2] = W_BISHOP;
    columnTab[7][5] = W_BISHOP;
    columnTab[7][3] = W_QUEEN;
    columnTab[7][4] = W_KING;

    // Hollow placement
    for(int i=3; i<6; i++)
    {
        for(int j=0; j<8; j++)
        {
            columnTab[i][j] = HOLLOW;
        }
    }

    return columnTab;
}

void boardPrint(int** boardIn)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d ", boardIn[i][j]);
        }
        printf("\n");
    }
    printf("\n"); 
}