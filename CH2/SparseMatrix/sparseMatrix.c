#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

#define MAX_TERMS	101
#define MAX_COL		100
#define COMPARE(a, b)\
	({\
		int returnValue = 0;\
		if((a)>(b))\
			returnValue = 1;\
		else if((a)==(b))\
			returnValue = 0;\
		else\
			returnValue = -1;\
		returnValue;\
	})

//===================================================================
//
//===================================================================
term *create(int maxRow, int maxCol)
{
	term *a = (term *)malloc(MAX_TERMS*sizeof(term));
	a[0].row = maxRow;
	a[0].col = maxCol;
	a[0].value = 0;

	return a;
}

//===================================================================
//
//===================================================================
void addElement(term a[], int row, int col, int value)
{
	if(row<0 || row>=a[0].row)
		return;

	if(col<0 || col>=a[0].col)
		return;

	int i = 1;
	
	/* TODO: insert must in order */
	while(i<=a[0].value && row>=a[i].row) ++i;
	a[i].row = row, a[i].col = col, a[i].value = value;
	a[0].value++;
	
}

//===================================================================
//
//===================================================================
void printMatrix(term a[])
{
	int i = 0;
	printf("\n[0]\t%d\t%d\t%d\n", a[0].row, a[0].col, a[0].value);
	for(i=1; i<=a[0].value; ++i)
		printf("[%d]\t%d\t%d\t%d\n", i, a[i].row, a[i].col, a[i].value);
}

//===================================================================
//
//	O(column*elements)
//
//===================================================================
void transpose(term a[], term b[])
{
	/* b is set to the transpose of a */
	int n, i, j, currentb;
	n = a[0].value;			/* total number */
	b[0].row = a[0].col;	/* transpose */
	b[0].col = a[0].row;
	b[0].value = n;
	
	if(n>0){ /* non zero matrix */
		currentb = 1;
		for(i=0; i<a[0].col; ++i)
		/* transpose by the  columns in a */
			for(j=1; j<=n; ++j)
			/* find current column */
				if(a[j].col == i){
				/* match current column, add to b */
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					++currentb;
				}
	}
}

//===================================================================
//
//	O(2*column + 2*elements) = O(column + elements) 
//
//===================================================================
void fastTranspose(term a[], term b[])
{
	/**/
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int numCols = a[0].col;
	int numTerms, i, j;
	
	numTerms = a[0].value;
	b[0].row = a[0].col, b[0].col = a[0].row, b[0].value = a[0].value;
	
	if(numTerms > 0){
		for(i = 0; i < numCols; ++i)
		/* initialization */
			rowTerms[i] = 0;
		for(i = 1; i <= numTerms; ++i)
		/* record element number of every row in b */
			rowTerms[a[i].col]++;
		startingPos[0] = 1;
		for(i = 1; i < numCols; ++i)
		/* derive the start position of every row in b */
			startingPos[i] = 
				startingPos[i-1] + rowTerms[i-1];
		for(i = 1; i <= numTerms; ++i){
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

//===================================================================
//
//===================================================================
void add(term a[], term b[], term c[])
{
	if(a[0].row != b[0].row || a[0].col != b[0].col)
		return;
	
	int i = 1, j = 1, currentc = 1;
	int numTerm1, numTerm2;
	
	numTerm1 = a[0].value, numTerm2 = b[0].value;
	c[0].row = a[0].row, c[0].col = a[0].col;
	c[0].value = 0;	
	
	while(i <= numTerm1 && j <= numTerm2)
	{
		if(a[i].row < b[j].row) {
			c[currentc].row = a[i].row;
			c[currentc].col = a[i].col;
			c[currentc].value = a[i].value;
			++i;
		}
		else if(a[i].row > b[j].row) {
			c[currentc].row = b[j].row;
			c[currentc].col = b[j].col;
			c[currentc].value = b[j].value;
			++j;
		}
		else{
			if(a[i].col < b[j].col){
				c[currentc].row = a[i].row;
				c[currentc].col = a[i].col;
				c[currentc].value = a[i].value;
				++i;
			}
			else if(a[i].col > b[j].col){
				c[currentc].row = b[j].row;
				c[currentc].col = b[j].col;
				c[currentc].value = b[j].value;
				++j;
			}
			else
			{
				c[currentc].row = b[j].row;
				c[currentc].col = b[j].col;
				c[currentc].value = b[j].value;
				++i, ++j;					
			}
		}
		++currentc;
	}
	
	for(;i <= numTerm1; ++i) {
		c[currentc].row = a[i].row;
		c[currentc].col = a[i].col;
		c[currentc].value = a[i].value;
		++currentc;
	}
	
	for(;j <= numTerm1; ++j) {
		c[currentc].row = b[j].row;
		c[currentc].col = b[j].col;
		c[currentc].value = b[j].value;
		++currentc;
	}
	
	c[0].value = currentc-1;
}

//===================================================================
//
//===================================================================
void mmult(term a[], term b[], term d[])
{
	/* multiply two sparse matrices */
	int i, j, column, totalD = 0;
	int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].value;
	int colsB = b[0].col, totalB = b[0].value;
	int rowBegin = 1, row = a[1].row, sum = 0;
	term newB[MAX_TERMS];
	
	if(colsA != b[0].row){
		fprintf(stderr, "Incompatible matrices\n");
		exit(EXIT_FAILURE);
	}
	/* O(colB+totalB) */
	fastTranspose(b, newB);
	printMatrix(newB);
	/* set boundary condition */
	a[totalA+1].row = rowsA;
	newB[totalB+1].row = colsB;
	newB[totalB+1].col = 0;
	
	for(i = 1; i <= totalA;) {
		column = newB[1].row;
		for(j = 1; j <= totalB+1;) {
			printf("i=%d, j=%d, row=%d, column=%d\n", i, j, row, column);
			
			/* multiply row of a by column of b */
			if(a[i].row != row){
				storeSum(d, &totalD, row, column, &sum);
				i = rowBegin;
				for(; newB[j].row == column; ++j);
				column = newB[j].row;
			}
			else if(newB[j].row != column){
				storeSum(d, &totalD, row, column, &sum);
				i = rowBegin;
				column = newB[j].row;
			}
			else switch (COMPARE(a[i].col, newB[j].col)) {
				case -1: /* go to next term in a */
					i++;
					printf("case -1\n");
					break;
				case 0: /* add terms, go to next term in a and b */
					sum += (a[i++].value*newB[j++].value);
					printf("case 0\n");
					break;
				case 1: /* advance to next term in b */
					j++;
					printf("case 1\n");
					break;
				}
		} /* end of for j <= totalB+1 */
		for(; a[i].row == row; ++i);
		rowBegin = i; row = a[i].row;
	} /* end of for i <= totalA */
	d[0].row = rowsA;
	d[0].col = colsB;
	d[0].value = totalD;
}

//===================================================================
//
//===================================================================
void storeSum(term d[], int *totalD, int row, int column, int *sum)
{
	/* if *sum != 0, then it along with its row and column 
		position is stored as the *totalD+1 entry in d*/
	if(*sum)
		if(*totalD < MAX_TERMS) {
			d[++*totalD].row = row;
			d[*totalD].col = column;
			d[*totalD].value = *sum;
			*sum = 0;
		}
		else {
			fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
			  
			exit(EXIT_FAILURE);
		}
}