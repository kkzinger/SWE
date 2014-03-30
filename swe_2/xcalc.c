

/*

	File: xcalc.c
	Author: G. Katzinger
	Date: 16.04.14

	Basic command-line Calculator
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int pos=-1;

int pop(); //Funktion zum lesen vom Stack
void push(int wert); //Funktion zum schreiben auf stack
void print_stack(); //Funktion um Stack komplett auszugeben
int contr_brackets(char *opstring);
double solve_pattern(char *opstring, int start, int end);
int parse(char **string, double **ptr_num, char **ptr_op);
int is_digit(char c);

//-----------------------------------------------------------------
//			MAIN
//-----------------------------------------------------------------

int main(int argc, char **argv)
{
	int s, i;
	double result;

	if(contr_brackets(argv[1]) == -1) return EXIT_FAILURE;
	result = solve_pattern(argv[1],0,strlen(argv[1]));

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

	len = (int) strlen(opstring);
	printf("strlen bracket test %d\n",len);
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

double solve_pattern(char *opstring, int start, int end)
{
	int len;
	double result=0;
	double *ptr_num;
	char *ptr_op;

	len = (int) strlen(opstring);
	ptr_num = (double*) malloc((sizeof(double)*len)/2+1);	//Worst case every number is one digit long ex. 6+4+5 ->3 doubles needed
	if(ptr_num == NULL) return fprintf(stdout,"Malloc was not able to allocate memory");

	ptr_op = (char*) malloc(len/2);
	if(ptr_op == NULL) return fprintf(stdout,"Malloc was not able to allocate memory");

	parse(&opstring, &ptr_num, &ptr_op);

	return 0;
}

int parse(char **string, double **ptr_num, char **ptr_op)
{
	int len, i;
	double cnt;
	char *p, *op;
	double *num;

	p = *string;
	//printf("kontrolle: %s",p);
	num = *ptr_num;
	op = *ptr_op;

	len = (int) strlen(p);

	for(i=len-1;i>=0;i--)
	{
		cnt = 0;
		while(is_digit(p[i]) || p[i] == '.')
		{
			if(p[i] == '.')
			{
				//printf("cnt: %lf", pow(10,cnt));
				*num = *num / pow(10,cnt);	//If there is a comma, move the already read digits behind it
				cnt = 0;
			}else
			{
				//printf("vorher: %lf \n p[i]: %d\n", *num, p[i]%48);
				*num = *num + (p[i]%48) * pow(10,cnt);
				//printf("nacher: %lf \n", *num);
				cnt += 1;
			}
			if(!(is_digit(p[i-1]) || p[i-1] == '.')) num++;

			i--;
		}
		switch(p[i])
		{
			case '+': *op = p[i--]; op++; break;
			case '-': *op = p[i--]; op++; break;
			case '*': *op = p[i--]; op++; break;
			case '/': *op = p[i--]; op++; break;
		}
	}
	printf("after parse op: %c\n", **(ptr_op));
	printf("after parse: %lf\n", **(ptr_num);
	/*printf("after parse op: %c\n", (ptr_op+1)));
	printf("after parse: %lf\n", *(*(ptr_num+1)));
	printf("after parse op: %c\n", *(*(ptr_op+2)));
	printf("after parse: %lf\n", *(*(ptr_num+2)));*/
	return 0;

}

int is_digit(char c)
{
	if((c >= 48) && (c <=57)) return 1;

	return 0;
}
