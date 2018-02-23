/*
 * SudStack.c

 *
 *  Created on: Oct 2, 2015
 *      Author: Erika
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "SudStack.h"
#include "Puzzle.h"


//Creates a stack which keeps track of the size of the stack and will point a linked list of move
//structs
stackType * createSudStack(){
	stackType *stack = (stackType *) malloc(sizeof(stackType));
	if (stack == NULL) {
		printf("ERROR: malloc failed in createSudStack in SudStack.c\n");
		return NULL;
	}
	stack->size = 0;
	stack->top = NULL;
	return stack;
}

//Will put a move struct onto the stack and the stack will point to the most recent thing put in
void push(stackType * stack, moveType * node){
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

//Will take a moveStruct off of the stack and return that struct and then the stack will point to
//the next item in the list
moveType * pop(stackType * stack){
	if (stack->size == 0){
		return NULL;
	}
	moveType * temp = stack->top;
	stack->top = stack->top->next;
	temp->next = NULL;
	stack->size--;

	if (stack->size == 0){
		stack->top = NULL;
	}
	return temp;
}

//Shows what is at the top of the stack
moveType * peek(stackType * stack){
	return stack->top;
}

//Returns how many move structs are in the stack
int size(stackType * stack){
	return stack->size;
}

//Returns true if there is nothing in the stack and false if not
bool isEmpty(stackType * stack){
	return size(stack) == 0;
}
