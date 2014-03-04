#include <stdio.h>
#include <string.h>

int my_strlen(char s[])
{
	int iCount=0;

	while(s[iCount] != '\0') iCount++;

	return iCount;
}


int main()
{
/*	int iLength, iLength1;
	char string[101];

	printf("Geben Sie einen String ein:");
	scanf("%s", string);


	iLength = my_strlen(string);
	iLength1 = strlen(string);
	printf("\nDie Länge mit \"my_strlen\" ist %d", iLength);
	printf("\nDie Länge mit \"strlen\" ist %d\n", iLength1);
	return 0;
*/

	double i=5.5, j=0.8;
	int erg;

	erg=i/j;

	printf("%lf\n",(i/j));
	printf("%d\n",erg);

}

