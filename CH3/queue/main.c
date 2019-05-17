#include <stdio.h>
#include "queue.h"

int main()
{
	int i = 0, num;
	
	printf("input a number: ");
	scanf("%d", &num);
	
	CreateQueue();
	
	if(num > MAX_SIZE)
		num = MAX_SIZE;

	for(i = 0; i < num; ++i)
	{
		element item;
		item.key = i;
		AddQ(item);
	}
	
	printQ();
	printf("is full: %d\n", IsFull());

	for(i = 0; i < num/2; ++i)
		DeleteQ();
	printQ();

	for(i = 0; i < num/4; ++i)
	{
		element item;
		item.key = i+100;
		AddQ(item);
	}	
	printQ();

	printf("front = %d. rear = %d\n", front, rear);

	return 0;
}
