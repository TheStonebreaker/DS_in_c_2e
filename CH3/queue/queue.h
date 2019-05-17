#ifndef _QUEUE_H
#define _QUEUE_H

#define MAX_SIZE 	100

typedef struct
{
	int key;
}element;

int front, rear;
element queue[MAX_SIZE];

void CreateQueue();
int IsFull();
int IsEmpty();
element queueEmpty();
void AddQ(element e1);
element DeleteQ();
void printQ();

#endif
