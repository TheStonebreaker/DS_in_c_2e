#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 100
/*
move[0].vert = -1; move[0].horiz =  0;
move[1].vert = -1, move[1].horiz =  1;
move[2].vert =  0, move[2].horiz =  1;
move[3].vert =  1, move[3].horiz =  1;
move[4].vert =  1, move[4].horiz =  0;
move[5].vert =  1, move[5].horiz = -1;
move[6].vert =  0, move[6].horiz = -1;
move[7].vert = -1, move[7].horiz = -1;
*/
void createStack()
{
	top = -1;
	capacity = 1;
	stack = (element *)malloc(sizeof(element)*capacity);
}

int isEmpty()
{
	return (top == -1);
}

int isFull()
{
	return (top >= (capacity - 1));
}

void resize()
{
	capacity*=2;
	stack = (element *)realloc(stack, sizeof(element)*capacity);
}

void push(element e1)
{
	if(isFull())
		resize();

	stack[++top] = e1;	
}

element stackEmpty()
{
	fprintf(stderr, "stack is empty!\n");
	element err;
	err.row = err.col = -1;
	return err;
}

element pop()
{
	if(top == -1)
		return stackEmpty();
	else
		return stack[top--];
}

void printStack()
{/*
	int i = 0;
	printf("\nstack:\n");
	for(i = 0; i <= top; ++i)
		printf("%d ", stack[i].key);
	printf("\n");
	*/
}
