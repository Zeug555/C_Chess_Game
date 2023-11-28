/*
Author: Lïam LOTTE
Creation Date: 27/11/2023
Last Update: 28/11/2023
Title: move.c
*/

#include "move.h"

bool pieceMovement(int** boardIn, int xIn, int yIn, int xOut, int yOut)
{
    bool moveVerif;
    int currentPiece = boardIn[xIn][yIn];

    switch (currentPiece)
    {
        case W_PAWN:
            moveVerif = movementPawn(boardIn, xIn, yIn, xOut, yOut, 0);
            break;
        case B_PAWN:
            moveVerif = movementPawn(boardIn, xIn, yIn, xOut, yOut, 1);
            break;
            
        default:
            break;
    }

    return moveVerif;
}

bool validDemand(int xIn, int yIn, int xOut, int yOut)
{
    if((xOut>7)||(yOut>7)||(xOut<0)||(yOut<0))
    {
        return false;
    }
    
    else if((xIn>7)||(yIn>7)||(xIn<0)||(yIn<0))
    {
        return false;
    }

    return true;
}

bool movementPawn(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side)
{
    if(!validDemand(xIn, yIn, xOut, yOut))
    {
        printf("Your move is out of the board\n");
        return false;
    }

    // --- Black Side ---
    if(side==1)
    {
        int distanceX = xOut - xIn;
        int distanceY = yOut - yIn;
            
        if((distanceX==0)&&(distanceY == 1)&&(yOut==7)&&(boardIn[yOut][xOut]==0))
        {
            boardIn[yOut][xOut] = B_QUEEN;
            boardIn[yIn][xIn] = HOLLOW;
            return true;
        }

        else if((distanceX==0)&&(distanceY == 1)&&(boardIn[yOut][xOut]==0))
        {
            boardIn[yOut][xOut] = boardIn[yIn][xIn];
            boardIn[yIn][xIn] = HOLLOW; 
            return true;
        }

        else if((distanceX==0)&&(distanceY == 2)&&(yIn==1)&&(boardIn[yOut][xOut]==0))
        {
            boardIn[yOut][xOut] = boardIn[yIn][xIn];
            boardIn[yIn][xIn] = HOLLOW; 
            return true;
        }

        else if((distanceY == 1)&&((distanceX == 1)||(distanceX == -1))&&(boardIn[yOut][xOut]!=0)&&(boardIn[yOut][xOut]%2==1))
        {
            boardIn[yOut][xOut] = boardIn[yIn][xIn];
            boardIn[yIn][xIn] = HOLLOW; 
            return true;
        }

        printf("You tried to move from (%d,%d) to (%d,%d), it is not possible with a pawn.\n", xIn, yIn, xOut, yOut);

        return false; // if none of theses case is triggered
    }

    // --- White Side ---
    int distanceX = xIn - xOut;
    int distanceY = yIn - yOut;
    
    if((distanceX==0)&&(distanceY == 1)&&(yOut==0)&&(boardIn[yOut][xOut]==0))
    {
        boardIn[yOut][xOut] = W_QUEEN;
        boardIn[yIn][xIn] = HOLLOW;
        return true;
    }

    else if((distanceX==0)&&(distanceY == 1)&&(boardIn[yOut][xOut]==0))
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW; 
        return true;
    }

    else if((distanceX==0)&&(distanceY == 2)&&(yIn==6)&&(boardIn[yOut][xOut]==0))
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW; 
        return true;
    }

    else if((distanceY == 1)&&((distanceX == 1)||(distanceX == -1))&&(boardIn[yOut][xOut]!=0)&&(boardIn[yOut][xOut]%2==0))
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW; 
        return true;
    }

    printf("You tried to move from (%d,%d) to (%d,%d), it is not possible with a pawn.\n", xIn, yIn, xOut, yOut);

    return false; // if none of theses case is triggered
}

bool movementRook(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side)
{
    if(!validDemand(xIn, yIn, xOut, yOut))
    {
        printf("Your move is out of the board\n");
        return false;
    }

}
