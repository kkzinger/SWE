#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	int i, n=0, *m;

	srand(time(NULL));

	printf("Bitte geben Sie die Anzahl der Zufallszahlen ein:");
	scanf("%d", &n);

	m = malloc(n*sizeof(double));

	for(i=0;i<n;i++)
	{
		m[i]=(double)rand()/RAND_MAX;
	}

	return 0;
}
