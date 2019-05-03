#include <stdio.h>

#define MAX_SIZE 22

int arr[MAX_SIZE];

int main()
{
	int i, val = 0-MAX_SIZE/2+1;
	for( i = 0; i < MAX_SIZE; ++i,++val){
		arr[i] = val;
		printf("%d ",arr[i]);
	}
	printf("\n");

	int *a = arr + MAX_SIZE/2 - 1;
	for(i = -10; i < MAX_SIZE/2; ++i)
		printf("a[%d]\t= %d\n",i, a[i]);

	return 0;
}
