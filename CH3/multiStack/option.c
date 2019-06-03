#include <stdio.h>
#include "option.h"

char shortOption[] ={'i','d','p','q'};
char longOption[][MAX_STRING_SIZE] = 
{
	"insert an element",
	"delete an element",
	"print the container",
	"quit"
};

void printOption()
{
	int i, size = sizeof(shortOption)/sizeof(shortOption[0]);
	printf("\nOptions:\n");
	for(i = 0; i < size; ++i)
		printf("%c\t-\t%s\n", shortOption[i], longOption[i]);
}
