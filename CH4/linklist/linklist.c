#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

#define IS_EMPTY(ptr) (!(ptr))

listPointer create2(int data1, int data2)
{
	listPointer first, second;
	first = (listPointer)malloc(sizeof(listNode));
	second = (listPointer)malloc(sizeof(listNode));
	first->data = data1;
	first->link = second;
	second->data = data2;
	second->link = NULL;

	return first;
}

void Insert(listPointer *first, listPointer x, int data)
{
	listPointer temp;
	temp = (listPointer)malloc(sizeof(listNode));
	temp->data = data;
	
	if(*first)
	{
		temp->link = x->link;
		x->link = temp;
	}
	else
	{
		temp->link = NULL;
		*first = temp;
	}
}

void Delete(listPointer *first, listPointer trail, listPointer x)
{
	if(trail)
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}


void PrintList(listPointer first)
{
	printf("The list contains: ");
	for(; first; first = first->link)
		printf("%4d", first->data);
	printf("\n");
}
