#ifndef _STACK_H
#define _STACK_H

#define MAX_SIZE 100

typedef struct{
	short int row;
	short int col;
	short int dir;
} element;

typedef struct{
	short int vert;
	short int horiz;
}offsets;

offsets move[8];

void createStack();
int isEmpty(); 
int isFull();
void resize();
void push(element e1);
element pop();
element stackEmpty();
void printStack();

element *stack;
int top;
int capacity;

#endif
