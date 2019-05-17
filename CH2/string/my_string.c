#include <stdio.h>
#include "my_string.h"

#define MAX_STRING_SIZE		100
#define MAX_PATTERN_SIZE	100

int failure[MAX_PATTERN_SIZE];
char string[MAX_STRING_SIZE];
char pat[MAX_PATTERN_SIZE];

/* compute the pattern's failure function */
void fail(char *pat)
{
	int i = 0, j = 0;
	int n = strlen(pat);
	failure[0] = -1;
	for(j = 1; j < n; ++j)
	{
		i = failure[j-1];
			
		while((i >= 0) && (pat[j] != pat[i+1]))
			i = failure[i];
		
		if(pat[j] == pat[i+1])
			failure[j] = i+1;
		else
			failure[j] = -1;
	}
}

/* Knuth, Morris, Pratt string matching algorithm */
int pmatch(char *string, char *pat)
{
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	while(i < lens && j < lenp)
	{
		//printf("(i,j)=(%d,%d)\n",i,j);
		if(string[i] == pat[j])
		{ ++i; ++j;}
		else if(j == 0) ++i;
		else j = failure[j-1]+1;
	}
	return (j == lenp ? i-lenp : -1);
}

/* insert string src into string des at position i */
void strnins(char *des, char *src, int i)
{
	char string[MAX_STRING_SIZE], *temp = string;
	
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

int	nfind(char *string, char *pat)
{/* match the last character first, and then match from beginning */
	int i, j, start = 0;
	int lasts = strlen(string) - 1;
	int lastp = strlen(pat) - 1;
	int endmatch = lastp;

	for(i = 0; endmatch <= lasts; ++endmatch, ++start)
	{
		if(string[endmatch] == pat[lastp])
			for(j = 0, i = start; j < lastp && string[i] == pat[j]; ++i, ++j);

		if(j == lastp)
			return start;
	}
	return -1;
}

int main()
{
	char s1[MAX_STRING_SIZE], s2[MAX_STRING_SIZE];
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	strcpy(s1, "ababacc");
	strcpy(s2, "abaa");
	fail(s2);
	int i = 0, find = 0;
	for(i = 0; i < strlen(s2); ++i)
		printf("%d ",failure[i]);
	printf("\n");
	find = pmatch(s1, s2);
	if(find == -1)
		printf("Not found\n");
	else
		printf("find at %d\n", find);

}	
