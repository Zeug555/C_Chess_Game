/*
Author: Lïam LOTTE
Creation Date: 29/11/2023
Last Update: 29/11/2023
Title: game.h
*/

#pragma once
#include "game.h"
#include "move.h"

// Manage the core of the game
bool startGame();
void gameGlobal();
char playTurn(int **boardIn, int *adrTurn);
bool verifCheckmate(int **boardIn, int *adrTurn);
int* kingPosition(int **boardIn, int *adrTurn);1