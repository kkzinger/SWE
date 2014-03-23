/*
	File: arr_c.c
	Author: Katzinger G.
	Date: 05.11.13

	Exercise for programming with arrays

*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ANZ 10000 

int main()
{

	int iArr[ANZ],i,iSum=0,iMin,iMax,iMaxPos,iMinPos;
	double dAvg;

	srand(time(NULL));


	if(ANZ<=6)
	{

		for(i=0;i<ANZ;i++)
		{

			printf("Please input a number for adress %d:", i);
			scanf("%d", &iArr[i]);
		}

	}else
	{
		for(i=0;i<ANZ;i++)
		{

			iArr[i] = rand()%100+1;

		}
	}

	iMin = iMax = iArr[0];


	for(i=0;i<ANZ;i++)
	{

		if(iArr[i]<iMin) 
		{
			iMin = iArr[i];
			iMinPos = i;
		}

		if(iArr[i]>iMax)
		{
			iMax = iArr[i];
			iMaxPos = i;
		}

		iSum+=iArr[i];
		dAvg=(double)iSum/ANZ;
	}

	/*-----Output the  Array-------*/

	/*for(i=0;i<ANZ;i++)
	{

		printf("Adresse %d: %d\n", i, iArr[i]);
	}*/

	printf("Min: %d\nPosition of Min: %d\nMax: %d\nPosition of Max: %d\nSum: %d\nAverage: %lf\n", iMin, iMinPos, iMax, iMaxPos, iSum, dAvg);

	return 0;
}

