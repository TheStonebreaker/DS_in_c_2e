#include <stdio.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

#define EXIT_ROW 9
#define EXIT_COL 6

short int maze[][8] = 
{
	{-1,-1,-1,-1,-1,-1,-1,-1},
	{-1, 0, 0, 0, 0, 0, 1,-1},
	{-1, 1, 1, 1, 1, 1, 0,-1},
	{-1, 1, 0, 0, 0, 0, 1,-1},
	{-1, 0, 1, 1, 1, 1, 1,-1},
	{-1, 1, 0, 0, 0, 0, 1,-1},
	{-1, 1, 1, 1, 1, 1, 0,-1},
	{-1, 1, 0, 0, 0, 0, 1,-1},
	{-1, 0, 1, 1, 1, 1, 1,-1},
	{-1, 1, 0, 0, 0, 0, 0,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1},
};

short int mark[][8] = 
{
	{-1,-1,-1,-1,-1,-1,-1,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1},
};

void path()
{
	int i, row, col, dir, nextRow, nextCol, found = FALSE;
	element position;
	mark[1][1] = 1;
	position.row = 1, position.col = 1, position.dir = 0;
	push(position);	
	
	while(top > -1 && !found)
	{
		position = pop();
		row = position.row, col = position.col, dir = position.dir;
		while(dir < 8 && !found)
		{
			/* move in direction dir */
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if(nextRow == EXIT_ROW && nextCol == EXIT_COL)
			{
				found = TRUE;
				position.row = row, position.col = col, position.dir = dir;
				push(position);
				position.row = nextRow, position.col = nextCol, position.dir = 0;
				push(position);
			}
			else if(!maze[nextRow][nextCol] && 
					!mark[nextRow][nextCol])
			{
				mark[nextRow][nextCol] = 1;
				position.row = row, position.col = col;
				position.dir = ++dir;
				push(position);
				row = nextRow, col = nextCol, dir = 0;
			}
			else ++dir;
		}	
	}
	if(found)
	{
		printf("The path is:\n");
		printf("row\tcol\n");
		for(i = 0; i <= top; ++i)
			printf("%d\t%d\n", stack[i].row, stack[i].col);
		/*
		printf("%d\t%d\n", row, col);
		printf("%d\t%d\n", EXIT_ROW, EXIT_COL);
		*/
	}
	else
		printf("The maze doesn't have a path\n");

}

int main()
{
	move[0].vert = -1; move[0].horiz =  0;
	move[1].vert = -1, move[1].horiz =  1;
	move[2].vert =  0, move[2].horiz =  1;
	move[3].vert =  1, move[3].horiz =  1;
	move[4].vert =  1, move[4].horiz =  0;
	move[5].vert =  1, move[5].horiz = -1;
	move[6].vert =  0, move[6].horiz = -1;
	move[7].vert = -1, move[7].horiz = -1;
	createStack();
	path();	
}
