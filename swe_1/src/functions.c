#include <stdio.h>
#include <math.h>

double dPythagoras(double a, double b)
{

	double c = 0.0;
	c = sqrt(a*a+b*b);
	return c;
}

int main()
{

	double a_,b_,dErgeb;

	printf("Erste Seitenlänge: ");
	scanf("%lf", &a_);
	printf("\nZweite Seitenlänge: ");
	scanf("%lf", &b_);
	dErgeb= dPythagoras(a_, b_);

	printf("\nErgebnis: %lf\n", dErgeb);

	return 0;
}
