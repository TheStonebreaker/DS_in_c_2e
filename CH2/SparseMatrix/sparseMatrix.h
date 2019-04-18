#ifndef SPARSEMATRIX_H_
#define SPARSEMATRIX_H_

typedef struct
{
	int row;
	int col;
	int value;
}term;

term	*create(int maxRow, int maxCol);
void	addElement(term a[], int row, int col, int value);
void	printMatrix(term a[]);
void	transpose(term a[], term b[]);
void	fastTranspose(term a[], term b[]);
void	add(term a[], term b[], term c[]);
void	mmult(term a[], term b[], term d[]);
void	storeSum(term d[], int *totalD, int row, int column, int *sum);

#endif
