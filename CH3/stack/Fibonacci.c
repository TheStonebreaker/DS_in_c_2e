#include <stdio.h>

int fibon(int n)
{
	if(n == 1)
		return 1;
	else if(n <= 0)
		return 0;
	else
		return fibon(n-1)+fibon(n-2);
}

int main()
{
	int i = 0, num = 0;
	printf("input the number of Fibonacci sequence: ");
	scanf("%d",&num);
	
	for(i = 0; i < num; ++i)
		printf("%d ",fibon(i));
	printf("\n");

	return 0;
}
