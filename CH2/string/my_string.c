#include <stdio.h>
#include "my_string.h"

#define MAX_SIZE 100

/* insert string src into string des at position i */
void strnins(char *des, char *src, int i)
{
	char string[MAX_SIZE], *temp = string;
	
	memset(temp, 0, sizeof(temp));

	if(i < 0 || i > strlen(des))
	{
		fprintf(stderr, "Position is out of boundary\n");
		return;
	}

	if(!strlen(des))
		strcpy(temp, src);
	else if(strlen(src))
	{
		strncpy(temp, des, i);
		strcat(temp, src);
		strcat(temp, des+i);
		strcpy(des, temp);
	}
}

void strnins2(char *des, char *src, int i)
{
	int index = 0, index2 = 0;
	
	if(i < 0 || i > strlen(des))
	{
		fprintf(stderr, "Position is out of boundary\n");
		return;
	}
	
	if(!strlen(des))
		strcpy(des, src);
	else if(strlen(src))
	{
		index = strlen(des) + strlen(src) - 1;
		index2 = strlen(src) - 1;
		while(index >= 0)
		{
			if(index >= (i+strlen(src)))
				des[index] = des[index -strlen(src)];
			else if(index >= i)
				des[index] = src[index2--];
			--index;
		}	
	}
}

int main()
{
	char s1[MAX_SIZE], s2[MAX_SIZE];
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	strcpy(s1, "auto");
	strcpy(s2, "mobile");
	printf("s1 = %s, s2 = %s\n",s1, s2);
	strnins2(s1,s2,4);
	printf("s1 = %s, s2 = %s\n",s1, s2);
}
