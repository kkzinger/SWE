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

int main(int argc, char *argv[])
{
	int s, i, len = 0;

	len = strlen(argv[1]);

	for(i=0;i<=len;i++)
	{
		if(!(strchr(argv[1], '(') && strchr(argv[1], ')'))) break;

		if(strchr(argv[1], '(')) push(1);

		if(strchr(argv[1], ')')) 
		{
			s = pop();
			if(s == -2) fprintf(stdout,"Syntax Error (Klammern)");
		}
	}

	return 0;
}

int pop()
{

	if(pos > -1)
		return stack[pos--];
	//fprintf(stderr,"Stack empty!\n");
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

	while(i != 0)
	{
		printf("Pos. %d: %6d\n",i+1,stack[i]);
		i--;
	}
}
