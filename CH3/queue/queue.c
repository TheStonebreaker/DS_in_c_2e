#include <stdio.h>
#include <limits.h>
#include "queue.h"

void CreateQueue()
{
	//front = rear = -1;
	front = rear = 0;
}

int IsEmpty()
{
	return front == rear;
}

int IsFull()
{
	//return rear == MAX_SIZE -1;
	return front == ((rear + 1) % MAX_SIZE);
}

void AddQ(element e1)
{
	if(IsFull())
		return;

	//queue[++rear] = e1;
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = e1;
}

element queueEmpty()
{
	element empty;
	empty.key = INT_MIN;

	return empty;
}

element DeleteQ()
{
	if(IsEmpty())
		return queueEmpty();

	//return queue[++front];
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

void printQ()
{
	int i;
	
	printf("\nqueue: ");
	/*
	for(i = front+1; i<= rear && i != -1; ++i)
		printf("%d ", queue[i].key);
	printf("\n");
	*/

	for(i = front + 1; i != rear; i = (i+1)%MAX_SIZE)
		printf("%d ", queue[i].key);
	printf("%d\n",queue[i].key);
}
