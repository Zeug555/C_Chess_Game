/*
Author: Lïam LOTTE
Creation Date: 27/11/2023
Last Update: 29/11/2023
Title: move.c
*/

#include "move.h"

bool pieceMovement(int** boardIn, int *adrTurn, int xIn, int yIn, int xOut, int yOut)
{
    bool moveVerif;
    int currentPiece = boardIn[yIn][xIn];
    int side =  (*adrTurn)%2;

    if((boardIn[yIn][xIn]%2 != side)||(boardIn[yIn][xIn]==0))
    {
        printf("The chosen piece is not at you\n");
        return false;
    }

    switch (currentPiece)
    {
        case W_PAWN:
        case B_PAWN:
            moveVerif = movementPawn(boardIn, xIn, yIn, xOut, yOut, side);
            break;

        case W_ROOK:
        case B_ROOK:
            moveVerif = movementRook(boardIn, xIn, yIn, xOut, yOut, side);
            break;
        
        case W_BISHOP:
        case B_BISHOP:
            moveVerif = movementBishop(boardIn, xIn, yIn, xOut, yOut, side);
            break;

        case W_KNIGHT:
        case B_KNIGHT:
            moveVerif = movementKnight(boardIn, xIn, yIn, xOut, yOut, side);
            break;

        case W_KING:
        case B_KING:
            moveVerif = movementKing(boardIn, xIn, yIn, xOut, yOut, side);
            break;

        case W_QUEEN:
        case B_QUEEN:
            moveVerif = movementQueen(boardIn, xIn, yIn, xOut, yOut, side);
            break;

        default:
            moveVerif = false;
            break;
    }

    return moveVerif;
}

bool validDemand(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side)
{
    // Board limits verification
    if((xOut>7)||(yOut>7)||(xOut<0)||(yOut<0))
    {
        printf("You tried to move your piece out of the map.\n");
        return false;
    }    
    else if((xIn>7)||(yIn>7)||(xIn<0)||(yIn<0))
    {
        printf("You tried to move a piece which is out of the board (this is not possible)\n");
        return false;
    }
    // Friend smash verification
    if(boardIn[yOut][xOut] != 0)
    {
        if(boardIn[yOut][xOut]%2 == side)
        {
            printf("You tried to smash a friend !\n");
            return false;
        }
    }

    return true;
}

bool lineMoveVerif(int** boardIn, int xIn, int yIn, int xOut, int yOut)
{
    int distanceX = xOut - xIn;
    int distanceY = yOut - yIn;

    // If the player wants to move the piece on the x line
    if (yIn == yOut)
    {
        // Want to move on the right
        if (distanceX > 0)
        {
            for (int i = xIn + 1; i < xOut; ++i)
            {
                if (boardIn[yOut][i] != HOLLOW)
                {
                    printf("There is a piece in the path of your X move\n");
                    return false;
                }
            }
            return true;
        }
        // Want to move on the left
        else if (distanceX < 0)
        {
            for (int i = xIn - 1; i > xOut; --i)
            {
                if (boardIn[yOut][i] != HOLLOW)
                {
                    printf("There is a piece in the path of your X move\n");
                    return false;
                }
            }
            return true;
        }
    }
    // If the player wants to move the rook on the y line
    else if (xIn == xOut)
    {
        // Want to move down
        if (distanceY > 0)
        {
            for (int i = yIn + 1; i < yOut; ++i)
            {
                if (boardIn[i][xOut] != HOLLOW)
                {
                    printf("There is a piece in the path of your Y move\n");
                    return false;
                }
            }
            return true;
        }
        // Want to move up
        else if (distanceY < 0)
        {
            for (int i = yIn - 1; i > yOut; --i)
            {
                if (boardIn[i][xOut] != HOLLOW)
                {
                    printf("There is a piece in the path of your Y move\n");
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool diagMoveVerif(int** boardIn, int xIn, int yIn, int xOut, int yOut)
{
    int distanceX = xOut - xIn;
    int distanceY = yOut - yIn;

    if(abs(distanceX) == abs(distanceY))
    {
        if ((distanceX>0)&&(distanceY>0))
        {
            for(int i = 1; i<abs(distanceX); i++)
            {
                if(boardIn[yIn+i][xIn+i]!=HOLLOW)
                {
                    printf("There is a piece in the path of your move\n");
                    return false;
                }
            }
            return true;
        }

        else if ((distanceX>0)&&(distanceY<0))
        {
            for(int i = 1; i<abs(distanceX); i++)
            {
                if(boardIn[yIn-i][xIn+i]!=HOLLOW)
                {
                    printf("There is a piece in the path of your move\n");
                    return false;
                }
            }
            return true;
        }

        else if ((distanceX<0)&&(distanceY>0))
        {
            for(int i = 1; i<abs(distanceX); i++)
            {
                if(boardIn[yIn+i][xIn-i]!=HOLLOW)
                {
                    printf("There is a piece in the path of your move\n");
                    return false;
                }
            }
            return true;
        }
        
        else if ((distanceX<0)&&(distanceY<0))
        {
            for(int i = 1; i<abs(distanceX); i++)
            {
                if(boardIn[yIn-i][xIn-i]!=HOLLOW)
                {
                    printf("There is a piece in the path of your move\n");
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool movementPawn(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side)
{
    if(!validDemand(boardIn, xIn, yIn, xOut, yOut, side))
    {
        printf("Your request is impossible for your Pawn.\n");
        return false;
    }

    // --- Black Side ---
    if(side==1)
    {
        int distanceX = xOut - xIn;
        int distanceY = yOut - yIn;

        // Pawn transformation into Queen at the end of the board  
        if((distanceX==0)&&(distanceY == 1)&&(yOut==7)&&(boardIn[yOut][xOut]==0))
        {
            boardIn[yOut][xOut] = B_QUEEN;
            boardIn[yIn][xIn] = HOLLOW;
            return true;
        }

        // Pawn basic movement
        else if((distanceX==0)&&(distanceY == 1)&&(boardIn[yOut][xOut]==0))
        {
            boardIn[yOut][xOut] = boardIn[yIn][xIn];
            boardIn[yIn][xIn] = HOLLOW; 
            return true;
        }

        // Pawn start movement
        else if((distanceX==0)&&(distanceY == 2)&&(yIn==1)&&(boardIn[yOut][xOut]==0))
        {
            boardIn[yOut][xOut] = boardIn[yIn][xIn];
            boardIn[yIn][xIn] = HOLLOW; 
            return true;
        }

        // Pawn which strike an other enemy piece
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
    
    // Pawn transformation into Queen at the end of the board  
    if((distanceX==0)&&(distanceY == 1)&&(yOut==0)&&(boardIn[yOut][xOut]==0))
    {
        boardIn[yOut][xOut] = W_QUEEN;
        boardIn[yIn][xIn] = HOLLOW;
        return true;
    }

    // Pawn basic movement
    else if((distanceX==0)&&(distanceY == 1)&&(boardIn[yOut][xOut]==0))
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW; 
        return true;
    }

    // Pawn start movement
    else if((distanceX==0)&&(distanceY == 2)&&(yIn==6)&&(boardIn[yOut][xOut]==0))
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW; 
        return true;
    }

    // Pawn which strike an other enemy piece
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
    if(!validDemand(boardIn, xIn, yIn, xOut, yOut, side))
    {
        printf("Your request is impossible for your Rook.\n");
        return false;
    }

    // Check if you have a piece in your path
    if(lineMoveVerif(boardIn, xIn, yIn, xOut, yOut) == true)
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW;
        return true;
    }

    printf("You tried to move from (%d,%d) to (%d,%d), it is not possible with a rook.\n", xIn, yIn, xOut, yOut);
    return false;
}

bool movementBishop(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side)
{
    if(!validDemand(boardIn, xIn, yIn, xOut, yOut, side))
    {
        printf("Your request is impossible with your bishop.\n");
        return false;
    }

    // Check if you have a piece in your path
    if(diagMoveVerif(boardIn, xIn, yIn, xOut, yOut) == true)
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW;
        return true;
    }

    printf("You tried to move from (%d,%d) to (%d,%d), it is not possible with a bishop.\n", xIn, yIn, xOut, yOut);
    return false;
}

bool movementKnight(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side)
{

    int distanceX = abs(xIn - xOut);
    int distanceY = abs(yIn - yOut);

    // Is your movement into your range of action ?
    if ((distanceX == 1 && distanceY == 2) || (distanceX == 2 && distanceY == 1))
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW;
        return true;
    }

    printf("You tried to move from (%d,%d) to (%d,%d), it is not possible with a knight.\n", xIn, yIn, xOut, yOut);
    return false;
}

bool movementQueen(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side)
{
    if(!validDemand(boardIn, xIn, yIn, xOut, yOut, side))
    {
        printf("Your request is impossible with your queen.\n");
        return false;
    }

    // Check if you have a piece in your path
    if((diagMoveVerif(boardIn, xIn, yIn, xOut, yOut)||lineMoveVerif(boardIn, xIn, yIn, xOut, yOut))== true)
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW;
        return true;
    }

    printf("You tried to move from (%d,%d) to (%d,%d), it is not possible with a queen.\n", xIn, yIn, xOut, yOut);
    return false;
}

bool movementKing(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side)
{
    if(!validDemand(boardIn, xIn, yIn, xOut, yOut, side))
    {
        printf("Your request is impossible for your king.\n");
        return false;
    }

    int distanceX = abs(xIn - xOut);
    int distanceY = abs(yIn - yOut);

    // Is your movement into your range of action ?
    if (distanceX <= 1 && distanceY <= 1)
    {
        boardIn[yOut][xOut] = boardIn[yIn][xIn];
        boardIn[yIn][xIn] = HOLLOW;
        return true;
    }

    printf("You tried to move from (%d,%d) to (%d,%d), it is not possible with a king.\n", xIn, yIn, xOut, yOut);
    return false;
}