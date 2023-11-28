/*
Author : Lïam LOTTE
Creation Date : 27/11/2023
Last Update : 27/11/2023
Title : init.h
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>

// ------- Piece name declaration ------- //

// Black pieces are odd
// White pieces are even
#define HOLLOW 0
#define B_PAWN 1
#define W_PAWN 2
#define B_ROOK 3
#define W_ROOK 4
#define B_BISHOP 5
#define W_BISHOP 6
#define B_KNIGHT 7
#define W_KNIGHT 8
#define B_QUEEN 9
#define W_QUEEN 10
#define B_KING 11
#define W_KING 12

// ------- Function declaration ------- //
int** boardInit(); 
void boardPrint();