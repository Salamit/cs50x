// Exercise 15 from Chapter 1 of C programming
// File 1ex15.c

/* This program prints a Fabrenheit-Celsius table
		for fahr = 0, 20, ...., 300; floating-point version */



#include <stdio.h>

float celsius(float fahr);

int main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;			/* lower limit of temperature table */
	upper = 300;		/* upper limit						*/
	step = 20;			/* step size						*/

	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f %6.1f\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
}

/* celsius: convert fahr into celsius 						*/
float celsius(float fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
	
