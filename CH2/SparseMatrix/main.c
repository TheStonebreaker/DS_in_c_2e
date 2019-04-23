#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

int main()
{
	term *a, *b, *c ,*d;
	a = create(6,6), b = create(6,6), c = create(6,6), d = create(6,6);
	addElement(a, 0, 0, 15);
	addElement(a, 0, 3, 22);
	addElement(a, 0, 5, -15);
	addElement(a, 1, 1, 11);
	addElement(a, 1, 2, 3);	
	addElement(a, 2, 3, -6);
	addElement(a, 4, 0, 91);	
	addElement(a, 5, 2, 28);
	
	printf("\nMatrix A:\n");
	printMatrix(a);
	fastTranspose(a, b);
	printf("\nMatrix B:\n");
	printMatrix(b);
	add(a, b, c);
	printf("\nMatrix C=A+B:\n");
	printMatrix(c);
	mmult(a, b, d);
	printf("\nMatrix D=A*B:\n");
	printMatrix(d);
	
	free(a), free(b), free(c), free(d);

	return 0;
}