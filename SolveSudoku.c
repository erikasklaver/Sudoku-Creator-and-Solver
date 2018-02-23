/*
 * SolveSudoku.c

 *
 *  Created on: Oct 2, 2015
 *      Author: Erika
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Puzzle.h"
#include "SudSolver.h"
#include "SudStack.h"

int main() {


	bool puzzleRead = readPuzzle();

	// don't do anything unless readPuzzle was successful
	if (puzzleRead) {

		printf("\n\nThe Puzzle\n");
		printPuzzle();

		solve();

		printf("\nThe Solution\n");
		printPuzzle();
	}

}
