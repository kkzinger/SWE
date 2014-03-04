//Swap programm with References

#include <stdlib.h>

void swap(int *a, int *b)
{
	int help;
	help=*a;
	*a=*b;
	*b=help;
}

int main()
{

	int a,b;
	

	printf("Wert 1 eingeben: ");
	scanf("%d",&a);

	printf("Wert 2 eingeben: ");
	scanf("%d",&b);

	swap(&a,&b);

	printf("Nach Swap\n");
	printf("Wert 1: %d\nWert 2: %d\n", a,b);

	return EXIT_SUCCESS;
}
