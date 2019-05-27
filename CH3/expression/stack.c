#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 100

void createStack()
{
	top = -1;
	capacity = 1;
	stack = (int *)malloc(sizeof(int)*capacity);
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
	stack = (int *)realloc(stack, sizeof(int)*capacity);
}

void push(int e1)
{
	if(isFull())
		resize();

	stack[++top] = e1;	
}

int stackEmpty()
{
	int err = INT_MIN;
	fprintf(stderr, "stack is empty!\n");
	return err;
}

int pop()
{
	if(top == -1)
		return stackEmpty();
	else
		return stack[top--];
}

void printStack()
{
	int i = 0;
	printf("\nstack:\n");
	for(i = 0; i <= top; ++i)
		printf("%d ", stack[i]);
	printf("\n");	
}
