//Übung Stack in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int pos = -1;

int pop(); //Funktion zum lesen vom Stack
void push(int wert); //Funktion zum schreiben auf stack
void print_stack(); //Funktion um Stack komplett auszugeben

int main()
{

	int i=0;

	srand(time(NULL));

	while(i <= STACK_SIZE)
	{
		push(rand()%10);
		i++;
	}

	push(4);

	print_stack();
	
	//printf("Pos: %d\n",pos);
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());
	printf("Pop ergebniss: %d\n", pop());

	print_stack();

	return EXIT_SUCCESS;
}

int pop()
{

	if(pos > -1)
		return stack[pos--];
	fprintf(stderr,"Stack empty!\n");
	return pos;
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
