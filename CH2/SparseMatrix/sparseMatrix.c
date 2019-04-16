#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

#define MAX_TERMS 101

term *create(int maxRow, int maxCol)
{
	term *a = (term *)malloc(MAX_TERMS*sizeof(term));
	a[0].row = maxRow;
	a[0].col = maxCol;
	a[0].value = 0;

	return a;
}

void addElement(term a[], int row, int col, int value)
{
	if(row<0 || row>=a[0].row)
		return;

	if(col<0 || col>=a[0].col)
		return;

	int i = 1;

	while(i<=a[0].value && row>=a[i].row) ++i;
	a[i].row = row, a[i].col = col, a[i].value = value;
	a[0].value++;
	
}

void printMatrix(term a[])
{
	int i = 0;
	printf("\n[0]\t%d\t%d\t%d\n", a[0].row, a[0].col, a[0].value);
	for(i=1; i<=a[0].value; ++i)
		printf("[%d]\t%d\t%d\t%d\n", i, a[i].row, a[i].col, a[i].value);
}

void	transpose(term a[], term b[])
{
	
}

void	add(term a[], term b[], term c[])
{
	
}

void	mmult(term a[], term b[], term d[])
{
	
}