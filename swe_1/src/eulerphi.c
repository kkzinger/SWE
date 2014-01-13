/*

	File: eulerphi.c
	Author: Katzinger G.
	Date: 30.10.2013

	Calculates the Euler Phi Number of a Integer that is read from the user.

*/

#include <stdio.h>

int fEulerPhi(int iNumber){

	int iEuler=0 ,i,e;

	if(iNumber==0){

		printf("Euler-Phi is not defined for '0'\n");

	}else iEuler=1;			//Because if iNumber isn't 0 the Euler-Phi Number must be at least 1


	for(i=1;i<iNumber;i++){

		e=0;

		e=iNumber%i;		//Division that returns the remainder

		if(e!=0) iEuler=iEuler+1;	//If ther is an remainder increase the result (iEuler) by one
	}

return iEuler;
}

int main(){

	int iNumber=0, iResult=0;

	printf("\nType in a number to calculate the Euler Phi-Function of it.\nNumber: ");
	scanf("%d", &iNumber);

	iResult = fEulerPhi(iNumber);

	printf("The Euler-Phi Number for %d is %d\n", iNumber,iResult);

return 0;
}

