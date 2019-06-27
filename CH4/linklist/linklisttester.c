#include <stdio.h>
#include "linklist.h"

int main()
{
	listPointer first, deleteNode;
	first = create2(20, 10);
	PrintList(first);
	Insert(&first, first, 50);
	Insert(&first, first, 40);
	PrintList(first);
	
	deleteNode = first;
	Delete(&first, NULL, deleteNode);
	PrintList(first);
}
