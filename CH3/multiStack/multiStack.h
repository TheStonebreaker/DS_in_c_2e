#ifndef _MULTISTACK_H
#define _MULTISTACK_H

#define MEMORY_SIZE 100
/* max number of stacks plus 1 */
#define MAX_STACKS  10

typedef struct {
	int val;
}element;

element memory[MEMORY_SIZE];
int top[MAX_STACKS];
int boundary[MAX_STACKS];
int n; /* number of stack entered by user */

void createMultiStack(int num);

/* push/pop from i-th stack */
void push(int i, element item);
element pop(int i);

/* full/empty check for i-th stack */
int isFull(int i);
int isEmpty(int i);
element stackEmpty();

void printStack(int num);

#endif
