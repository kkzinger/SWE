/*

	File: xcalc.c
	Author: G. Katzinger
	Date: 16.04.14

	Basic command-line Calculator
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int pos=-1;

int pop(); //Funktion zum lesen vom Stack
void push(int wert); //Funktion zum schreiben auf stack
void print_stack(); //Funktion um Stack komplett auszugeben
int contr_brackets(char *opstring);
double solve_pattern(char *opstring,int start,int end);
void parse(char **string, double **ptr_num, double **ptr_op);
int is_digit(char c);

//-----------------------------------------------------------------
//			MAIN
//-----------------------------------------------------------------

int main(int argc, char *argv[])
{
	int s, i;

	if(contr_brackets(argv[1]) == -1) return EXIT_FAILURE;
	solve_pattern(argv[1],0,strlen(argv[1]));

	//printf("\n\n isdigit Test: %d\n",is_digit('A'));
	print_stack();
	return 0;
}


//-----------------------------------------------------------------
//			FUNCTIONS
//-----------------------------------------------------------------
int pop()
{

	if(pos > -1)
		return stack[pos--];
	fprintf(stderr,"Stack empty!\n");
	return -2;
}

void push(int wert)
{
	if(pos < (STACK_SIZE-1))
		stack[++pos] = wert;
	else
		fprintf(stderr,"Stack is full!\n");
}

void print_stack()
{
	int i=STACK_SIZE-1;

	while(i >= 0)
	{
		printf("Pos. %d: %6d\n",i,stack[i]);
		i--;
	}
	printf("Stack Pos.: %d\n",pos);
}

int contr_brackets(char *opstring)
{
	int i, s, len;

	len = strlen(opstring);

	for(i=0;i<=len;i++)
	{

		if(opstring[i] == '[') 
		{
			push(i+1);
		}
		else if(opstring[i] == ']')
		{
			s = pop();
			if(s == -2)
			{
				fprintf(stdout,"Syntax Error (Klammern)\n");
				return -1;
			}
		}
	}

	if(pos != -1)
	{
		fprintf(stdout,"Syntax Error (Klammern)\n");
		return -1;
	}

	return 0;
}

double solve_pattern(char *opstring,int start,int end)
{
	double result=0;
	double *ptr_num, *ptr_op;

	parse(&opstring, &ptr_num, &ptr_op);

	return 0;
}

void parse(char **string, double **ptr_num, double **ptr_op)
{
	int c;
	char *p;

	p = *string;

	while(*p != '\0')
	{
		printf("test %c\n",*p);
		p++;
	}

}

int is_digit(char c)
{
	if((c >= 48) && (c <=57)) return 1;

	return 0;
}
