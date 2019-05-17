#include <stdio.h>

int number;
int results = 0;

void permutation(int out, int stack)
{
	/* all cars are on track */
	if(out == number)
		++results;
	/* some cars left */
	else if(out + stack < number)
		permutation(out, stack+1);

	if(stack > 0)
		permutation(out + 1, stack - 1);
}

int main()
{
	printf("input the numbers of tracks: ");
	scanf("%d", &number);
	results = 0;
	permutation(0,0);
	printf("results = %d\n", results);

	return 0;
}
