/*

	File: bmi.c
	Author: Katzinger G.
	Date : 29.10.13

	Calculates the BMI (Bodymassindex) and classifies the result
*/


#include <stdio.h>

int main (){

	double dWeight=0, dHeight=0, dBMI=0;

	//User information and poll
	printf("This program will calculate your BMI (Bodymassindex) and rate it\n");
	printf("Bodyweight in [kg]: ");
	scanf("%lf", &dWeight);
	printf("Bodyheight in [cm]: ");
	scanf("%lf", &dHeight);

	dHeight = dHeight / 100; //change [cm] in [m] for calculating
	dBMI = dWeight / (dHeight*dHeight); //Calculate BMI

	if (dBMI <= 16)
		printf("Your BMI is %.2lf this conforms critical underweight\n", dBMI);
	else if (dBMI >16 && dBMI <20)
		printf("Your BMI is %.2lf this conforms  underweight\n", dBMI);
	else if (dBMI >=20 && dBMI <25)
		printf("Your BMI is %.2lf this conforms critical normalweight\n", dBMI);
	else if (dBMI >=25)
		printf("Your BMI is %.2lf this conforms overweight\n", dBMI);

return 0;
}

