#ifndef _STACK_H
#define _STACK_H

#define MAX_SIZE 100

void createStack();
int isEmpty(); 
int isFull();
void resize();
void push(int e1);
int  pop();
int stackEmpty();
void printStack();

int *stack;
int top;
int capacity;

#endif
