/*
 * Puzzle.h
 *
 *  Created on: Oct 2, 2015
 *      Author: Erika
 */

#ifndef PUZZLE_H_
#define PUZZLE_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define DIMENSION 9
#define MAX_FILE_NAME_SIZE  20


// a move specififes a row, a column, and the digit that is at that spot;
// the stack will be a stack of these move structs
typedef struct move {
	int row;
	int col;
	int digit;
	struct move *next;
} moveType;


bool readPuzzle();
int getDigit(int row, int col);
void makeMove(int row, int col, int digit);
moveType *changeMove(int row, int col, int lastMove);
moveType *nextMove();
bool legalMove(int row, int col, int digit);
bool success();
void printPuzzle();




#endif /* PUZZLE_H_ */
