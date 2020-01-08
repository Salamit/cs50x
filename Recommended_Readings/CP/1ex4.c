/* Example 4 from Chapter 1, C Programming
2nd Edition
File 1ex4.c */

/* This program uses the corresponding Celsius values from the previous exercise to convert to Fahrenheit(fahr)
starting at -17.8 degrees C and increments by 16.7 degrees 
up to a final figure of 300 degrees C*/

#include <stdio.h>
main()
{

	float fahr, celsius, lower, upper, step;      /* Define the variables first */



	lower = -17.8;     /* Starting figure of the conversion table */
	upper = 150.0;   /* Highest figure of the conversion table. Chose 150 because this higher limit allows for 300 F to be printed to the console*/
	step = 16.7;     /* Increments in Fahr */

	/* My written version of the code without looking at the book*/


	celsius = lower;
	printf("%3s\t\t%s\n", "Celsius", "Fahrenheit");
	while (celsius <= upper) {
		fahr = ((9.0/5.0) * celsius) + 32.0;
		printf("%6.1f\t\t%6.1f\n", celsius, fahr);
		celsius += step;
	}

}