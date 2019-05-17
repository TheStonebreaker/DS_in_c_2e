#ifndef _STACK_H
#define _STACK_H

#define MAX_SIZE 100

typedef struct{
	int key;
} element;

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
