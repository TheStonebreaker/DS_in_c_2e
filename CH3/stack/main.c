#include <stdio.h>
#include "stack.h"

int main()
{
	element e1;
	int i, num;

	printf("input number = ");
	scanf("%d", &num);

	createStack();
	for(i = 1; i <= num; ++i)
	{
		e1.key = i;
		push(e1);
	}

	printStack();
	printf("top = %d, capacity = %d\n",top, capacity);
}
