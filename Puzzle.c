/*
 * Puzzle.c

 *
 *  Created on: Oct 2, 2015
 *      Author: Erika
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Puzzle.h"



// puzzle is a 2-d array
int puzzle[DIMENSION][DIMENSION];


// get a filename and read in the puzzle
bool readPuzzle() {

	FILE *inputf;
	char filename[MAX_FILE_NAME_SIZE];

	// get the file name
	printf("Please enter the problem file name: ");
	scanf("%s", filename);
	// make sure it can be opened
	if ((inputf = fopen(filename, "r")) == NULL) {
		printf("\nFile %s could not be opened.\n", filename );
		return false;
	}

	// code to read the digits in the file into a 2-d array taken from:
	// http://stackoverflow.com/questions/23577785/read-text-file-into-2d-array
	for (int i = 0; i < DIMENSION; i++) {
	    for (int j = 0; j < DIMENSION; j++) {
	        char c;
	        // scan a character from the file
	        fscanf(inputf, " %c", &c);

	        // if it's a digit, substract '0' from it to get the
	        // digit and put it in the array
	        if (isdigit((unsigned char)c))
	        	puzzle[i][j] = c - '0';
	        // otherwise, put a zero in the array
	        else
	        	puzzle[i][j] = 0;
	    }
	}

	// don't forget to close the file
	fclose (inputf);

	// file successfully read
	return true;

}


// get the digit from a specified location in the puzzle
int getDigit(int row, int col) {
    return puzzle[row][col];
}




// put a digit in a specified location in the puzzle
void makeMove(int row, int col, int digit) {
    puzzle[row][col] = digit;
}



// given a row and col and the last digit tried there, try all
// the remaining digits; if one of them is a legal move, make
// a move struct for that digit and return it; if not, make a
// move struct with digit zero to indicate that it was not possible
moveType *changeMove(int row, int col, int lastDigit) {

	moveType *move = (moveType *) malloc(sizeof(moveType));
	if (move == NULL) {
		printf("ERROR: malloc failed in changeMove in Puzzle.c\n");
		return NULL;
	}

	// try all the digits that come after lastDigit
	for (int next = lastDigit + 1; next <= DIMENSION; next++) {
		if (legalMove(row, col, next)) {
			move->row = row;
			move->col = col;
			move->digit = next;
			return move;
		}
	}

	// none of them were legal
	move->row = row;
	move->col = col;
	move->digit = 0;
	return move;
}




// go through the entire puzzle until you find a sapce with a 0,
// i.e. it's empty. Try all 9 digits; if one of them is a legal move,
// make a move struct for that digit and return it; if not, make a
// move struct with digit zero to indicate that it was not possible
moveType *nextMove() {

	moveType *move = (moveType *) malloc(sizeof(moveType));

    for (int row = 0; row < DIMENSION; row++) {
        for (int col = 0; col < DIMENSION; col++) {

            if (puzzle[row][col] == 0) {

            	// try all possible digits
                for (int next = 1; next <= DIMENSION; next++) {
                    if (legalMove(row, col, next)) {
            			move->row = row;
            			move->col = col;
            			move->digit = next;
            			return move;                    }
                }

                // none of the digits worked
    			move->row = row;
    			move->col = col;
    			move->digit = 0;
    			return move;            }

        }
    }

    // should never get here, because if there are no more
    // empty places, the puzzle is solved, but we have to
    // return something
    return NULL;
}





// check if a move is legal and return true if and only if it is
bool legalMove(int row, int col, int move) {

    // check row and col
    for (int i = 0; i < DIMENSION; i++) {
        if (puzzle[row][i] == move || puzzle[i][col] == move) {
            return false;
        }
    }

    // check the 3x3 group that [row,col] belongs to.
    int rGroup = row / 3;
    int cGroup = col / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[rGroup * 3 + i][cGroup * 3 + j] == move) {
                return false;
            }
        }
    }

    return true;
}



// if the puzzle has no more blank spaces, we have solved it
// (because we have been careful to only make legal moves)
bool success() {
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            if (puzzle[r][c] == 0)
                return false;
        }
    }
    return true;
}



// print out the puzzle in a nicely formatted way
void printPuzzle(){

    for (int r = 0; r < DIMENSION; r++){
        for (int c = 0; c < DIMENSION; c++){
            if (puzzle[r][c] == 0)
                printf("_ ");
            else
                printf("%d ", puzzle[r][c]);
        }
        printf("\n");
    }
    printf("\n");

}

