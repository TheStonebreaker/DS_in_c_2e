#include <stdio.h>
#include <limits.h>
#include "multiStack.h"
#include "option.h"

void createMultiStack(int num)
{
	int i;
	n = (num < MAX_STACKS ? num : MAX_STACKS);
	top[0] = boundary[0] = -1;
	for(i = 1; i < n; ++i)
		top[i] = boundary[i] = (MEMORY_SIZE)/n*i;
	boundary[n] = MEMORY_SIZE - 1;
	for(i = 0; i < MEMORY_SIZE; ++i)
		memory[i].val = 0;
	for(i=0; i<n; ++i)
		printf("top[%d]=%d, boundary[%d]=%d\n", i,top[i],i,boundary[i]);
}

int isFull(int i)
{
	return top[i] == boundary[i+1];
}

int isEmpty(int i)
{
	return top[i] == boundary[i];
}

element stackEmpty()
{
	element err;
	err.val = INT_MIN;
	return err;
}

void push(int i, element item)
{
	if(!isFull(i))
		memory[++top[i]] = item;
	else
		printf("Stack %d-th is full\n",i);
}

element pop(int i)
{
	element err;
	if(!isEmpty(i))
		return memory[top[i]--];
	else
	{
		printf("Stack %d-th is empty\n", i);
		return stackEmpty();
	}
}

void printStack(int num)
{
	if(num > MAX_STACKS)
	{
		printf("exceed max stack size: %d\n", MAX_STACKS);
		return;
	}
	
	if(isEmpty(num))
	{
		printf("stack %d is empty\n", num);
		return;
	}

	int i;
	printf("stack %d contains:\n", num);
	for(i = boundary[num]+1; i<=top[num]; ++i)
			printf("%d ",memory[i].val);
	printf("\n");
}

/* need to be tested */
int main()
{
	int num, i;
	printf("Input the stack number:");
	scanf("%d", &num);
	createMultiStack(num);
	element item;
	char op;
	do{
		printOption();
		while(scanf("%c", &op), op == '\n');
		switch(op)
		{
			case 'i':
				printf("Input the stack number to insert:");
				scanf("%d", &num);
				printf("Input the element to insert:");
				scanf("%d", &item.val);
				push(num, item);
				break;

			case 'd':
				printf("Input the stack number to delete:");
				scanf("%d", &num);
				printf("delete item %d from %d-th stack", pop(num).val, num);
				break;

			case 'p':
				printf("Input the stack number to print:");
				scanf("%d", &num);
				printStack(num);
				break;

			case 'q':
				break;

			default:
				printf("option %d not defined\n", op);
				break;
		}
	}while(op != 'q');
}
