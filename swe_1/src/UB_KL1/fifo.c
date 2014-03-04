//Übung für FIFO

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int my_fifo[MAX];
int up=0, down=0, cnt=0;

void enq(int wert); //Fügt werte in die Queue
int deq();	   //Holt werte aus der Queue
//void print_q();	   //Ausgabe gesamter Queue incl "up" "down"

int main()
{
	int i;

	for(i=0;i<MAX;i++)
	{
		enq(i+i);
	}

	printf("cnt: %d   up: %d    down: %d   Wert: %d\n",cnt,up,down,deq());
	printf("cnt: %d   up: %d    down: %d   Wert: %d\n",cnt,up,down,deq());
	printf("cnt: %d   up: %d    down: %d   Wert: %d\n",cnt,up,down,deq());
	printf("cnt: %d   up: %d    down: %d   Wert: %d\n",cnt,up,down,deq());
	printf("cnt: %d   up: %d    down: %d   Wert: %d\n",cnt,up,down,deq());

}

void enq(int wert)
{
	if((up == down) && (cnt == MAX))
	{
		fprintf(stderr,"my_fifo is full!\n");
	}
	else
		my_fifo[up] = wert;
		up += 1;
		up %= MAX;
		cnt += 1;
}

int deq()
{
	int item=0;

	if(cnt != 0)
	{
		item = my_fifo[down];
		down += 1;
		down %= MAX;
		cnt--;
	}
	else
		fprintf(stderr,"my_fifo is empty\n");

	return item;

}


