#ifndef _DEQUE_H
#define _DEQUE_H

typedef struct
{
	int key;
}element;

int front, rear;

void createDeque();
int isFull();
int isEmpty();
void pushFront(element item);
void pushBack(element item);
element popFront();
element popBack();

#endif
