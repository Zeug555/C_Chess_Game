/*
Author: Lïam LOTTE
Creation Date: 29/11/2023
Last Update: 29/11/2023
Title: game.c
*/

#include "game.h"

bool startGame()
{
    char response = 0;

    printf("\n\nHello world !\n");
    printf("Welcome to C Chess Game, a copy of chess programmed in C !\n\n");
    printf("Pieces are represented by numbers, white pieces are even, black are odd.\n\n");
    printf(" ------------ Black ----- White ---------\n");
    printf("PAWN :          1           2\n");
    printf("ROOK :          3           4\n");
    printf("BISHOP :        5           6\n");
    printf("KNIGHT :        7           8\n");
    printf("QUEEN :         9           10\n");
    printf("KING :          11          12\n\n");
    
    while(response != 'y' || response != 'n')
    {
        printf("Do you want to start the game ?\n");
        printf("y -> Yes, n -> No : ");
        scanf(" %c", &response);

        if(response == 'y')
            return true;
        else if (response == 'n')
        {
            return false;
        }
        
        printf("\n Hmmm ? I don't understand... can you repeat please ? ");
    }
}

void gameGlobal()
{
    // Variable init
    int turn;
    int **board;
    char checkmateOrQuit;

    // Game introduction
    bool response  = startGame();

    // If the user want to start a game
    if(response)
    {
        char restart = 'y';
        // Restart while the user says "yes"
        while(restart == 'y')
        {
            turn = 0; // Initialise the turn number to zero
            board = boardInit(); // Initialise the board
            printf("Ok, lezgo !\n");

            // The game work while there is no checkmate or a player that exit the game
            while((checkmateOrQuit!='c')||checkmateOrQuit!='q')
            {
                checkmateOrQuit = playTurn(&turn);
            }
            
            // Restart ?
            if(checkmateOrQuit == 'q')
            {
                printf("You quit your game, do you want to restart one ?\n");
                printf("y -> Yes, n -> No : ");
                scanf(" %c", &restart);
            }

            else if(checkmateOrQuit == 'c')
            {
                printf("Your game is finished, do you want to restart one ?\n");
                printf("y -> Yes, n -> No : ");
                scanf(" %c", &restart);
            }
        }
    }

    // Game exit
    printf("\n No problem byebye !\n");
    return;
}