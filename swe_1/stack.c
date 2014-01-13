#include <stdio.h>

int stack[5]; //globales array
int stack_size=0;

void push(int item) //Item in den Stack geben (Wenn Stack voll -- Fehler)
{
	if(stack_size > 4)
	{
		fprintf(stderr, "Stack ist voll\n");
		return;
	}

	stack[stack_size] = item;
	stack_size++;
}


int pop() //Das oberste Elemente aus dem Stack nehmen (Wenn Stack leer ist Fehlermeldung -1 zurückgeben)
{
	int item;
	if(stack_size == 0)
	{
		fprintf(stderr,"Stack leer!\n");
		return -1;
	}
	item = stack[stack_size -1];
	stack_size -= 1;
	return item;
}

int is_full()
{
	if(stack_size >4)
		return 1;
	else
		return 0;
}


int main()
{
	int read=0, out=0;

	while(read != -1)
	{
		printf("Zahl:");
		scanf("%d", &read);
		if(read != -1)
			push(read);

	}
	while(out != -1)
	{
		out = pop();

		if(out != -1)
			printf("%d ", out);
	}
	printf("\n");
	return 0;
}
