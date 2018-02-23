/*
 * SudSolver.c

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
#include "SudSolver.h"
#include "SudStack.h"


// uses a stack of move structs and some while loops to
// solve the Sudoku puzzle using backtracking
void solve() {

	//creates the stack that will hold all of the moves that solve the puzzle
	stackType * stack = createSudStack();

	//this while loop runs until the puzzle is completed
	while (!success()){

		//this creates a moveType struct which contains the next legal move
		moveType * move = nextMove();

		//if the digit in the moveType struct is not 0, then there was a legal move so the moveType
		//gets pushed onto the struct and the move is made in the puzzle
		if (move->digit != 0){
			push(stack, move);
			makeMove(move->row, move->col, move->digit);
		}

		//if the digit in the moveType struct is 0, then there are no more legal moves
		while(move->digit == 0){

			//if there are no more legal moves, then the last move was wrong so should be popped off
			//the stack and the move should be changed
			moveType * badMove = pop(stack);
			move = changeMove(badMove->row, badMove->col, badMove->digit);

			//once a legal move is found, put it on the stack
			if(move->digit != 0){
				push(stack, move);
			}
			//put the move into the actual puzzle
			makeMove(move->row, move->col, move->digit);

		}


	}






}

