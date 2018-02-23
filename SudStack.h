/*
 * SudStack.h
 *
 *  Created on: Oct 2, 2015
 *      Author: Erika
 */

#ifndef SUDSTACK_H_
#define SUDSTACK_H_

#include<stdio.h>
#include<stdlib.h>
#include "Puzzle.h"

//creates the stack struct which points to a list of move structs and remembers the size of the list
typedef struct stack {
	int size;
    moveType *top;
}stackType;

//the functions used in SudStack
stackType * createSudStack();
void push(stackType * stack, moveType * node);
moveType * pop(stackType * stack);
moveType * peek(stackType * stack);
int size(stackType * stack);
bool isEmpty(stackType * stack);


#endif /* SUDSTACK_H_ */
