#include <stdio.h>
#include "queue.h"

int main()
{
	int i = 0, num;
	
	printf("input a number: ");
	scanf("%d", &num);
	
	CreateQueue();
	
	for(i = 0; i < num; ++i)
	{
		element item;
		item.key = i;
		AddQ(item);
	}
	
	printQ();
	printf("is full: %d, capacity = %d\n", IsFull(), capacity);
	printf("front = %d. rear = %d\n", front, rear);

	for(i = 0; i < num/2; ++i)
		DeleteQ();
	printQ();

	for(i = 0; i < num/2; ++i)
	{
		element item;
		item.key = i+num;
		AddQ(item);
	}	
	printQ();
	printf("is full: %d, capacity = %d\n", IsFull(), capacity);
	printf("front = %d. rear = %d\n", front, rear);

	element item;
	item.key = num + num/2;
	AddQ(item);
	printQ();
	printf("is full: %d, capacity = %d\n", IsFull(), capacity);
	printf("front = %d. rear = %d\n", front, rear);
	return 0;
}
