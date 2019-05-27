#include <stdio.h>
#include <string.h>
#include "stack.h"

char expr[100];

/* eos: end of string */
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand}
precedence;

/* 	
	isp: in-stack precedence
	icp: in-coming precedence
*/
int isp[] = {0,19,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};

precedence getToken(char *symbol, int *n)
{/* get the next token */
	*symbol = expr[(*n)++];
	switch(*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '*': return times;
		case '/': return divide;
		case '%': return mod;
		case '\0': return eos;
		default:  return operand;
	}
}

void printToken(precedence token)
{
	char c = ' ';
	switch(token)
	{
		case lparen: c = '('; break;
		case rparen: c = ')'; break;
		case plus: 	 c = '+'; break;
		case minus:  c = '-'; break;
		case times:  c = '*'; break;
		case divide: c = '/'; break;
		case mod: 	 c = '%'; break;
	}
	printf("%c", c);
}

void postfix(void)
{/* output the postfix exprssion */
	char symbol;
	precedence token;
	int n = 0;
	top = 0;
	stack[0] = eos;
	for(token = getToken(&symbol, &n); token != eos;
		token = getToken(&symbol, &n))
	{
		if(token == operand)
			printf("%c",symbol);
		else if(token == rparen)
		{
			while(stack[top] != lparen)
				printToken(pop());
			pop();
		}
		else
		{
			while(isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
	}

	while((token = pop())!=eos)
		printToken(token);
	printf("\n");
}

int eval(void)
{/* evaluate a postfix expression, expr, maintained as a global var, 
	Operands are assume to be single digit */
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	printf("symbol: %c, token = %d\n", symbol,token);
	while(token != eos)
	{
		if(token == operand)
		{
			push(symbol-'0');
		}
		else
		{
			op2 = pop(); op1 = pop();
			switch(token)
			{
				case plus: 	 push(op1+op2); break;
				case minus:	 push(op1-op2); break;
				case times:	 push(op1*op2); break;
				case divide: push(op1/op2); break;
				case mod:	 push(op1%op2); break;
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

int main()
{
	createStack();
	memset(expr, 0, sizeof(expr));
	printf("Input expression:");
	scanf("%s", expr);
	postfix();
	//printf("answer: %d\n",eval());
}

