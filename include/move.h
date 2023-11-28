/*
Author: Lïam LOTTE
Creation Date: 27/11/2023
Last Update: 28/11/2023
Title: move.h
*/

#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "board.h"

bool pieceMovement(int** boardIn, int xIn, int yIn, int xOut, int yOut);

bool validDemand(int xIn, int yIn, int xOut, int yOut);

bool movementPawn(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side);
bool movementRook(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side);
bool movementBishop(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side);
bool movementKnight(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side);
bool movementQueen(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side);
bool movementKing(int** boardIn, int xIn, int yIn, int xOut, int yOut, int side);