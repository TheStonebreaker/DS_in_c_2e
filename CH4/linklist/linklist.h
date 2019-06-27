#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef struct listNode *listPointer;
typedef struct listNode
{
	int data;
	listPointer link;
}listNode;

listPointer create2(int data1, int data2);
void Insert(listPointer *first, listPointer x, int data);
void Delete(listPointer *first, listPointer trail, listPointer x);
void PrintList(listPointer first);

#endif
