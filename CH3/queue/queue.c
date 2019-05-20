#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void CreateQueue()
{
	//front = rear = -1;
	front = rear = 0;
	capacity = 1;
	queue = (element *)malloc(sizeof(element)*capacity);
}

int IsEmpty()
{
	return front == rear;
}

int IsFull()
{
	//return rear == MAX_SIZE -1;
	return front == ((rear + 1) % capacity);
}

void resize()
{
	
	int newCapacity = capacity * 2;
	queue = (element *)realloc(queue, sizeof(element)*newCapacity);
	
	if(front > rear)
	{
		int i, j = newCapacity -1;
		for(i = capacity - 1; i > front; --i, --j)
			queue[j] = queue[i];
		front = j;
	}
	capacity = newCapacity;
}

void AddQ(element e1)
{
	if(IsFull())
		resize();

	//queue[++rear] = e1;
	rear = (rear + 1) % capacity;
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
	front = (front + 1) % capacity;
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

	for(i = front + 1; i != rear; i = (i+1)%capacity)
		printf("%d ", queue[i].key);
	printf("%d\n",queue[i].key);
}
