//Example 3 from Chapter 1, C Programming
//2nd Edition
//File 1ex3.c

#include <stdio.h>

/* This program provides a Fahrenheit-Celsius conversion table
	for fahr = 0, 20, ..., 300 */

main()
{

	float fahr, celsius;      /* Define the variables first */
	int lower, upper, step;



	lower = 0;     /* Starting figure of the conversion table */
	upper = 300;   /* Highest figure of the conversion table */
	step = 30;     /* Increments in Fahr */

	/* My written version of the code without looking at the book*/


	fahr = lower;
	printf("%3s\t%s\n", "Fahrenheit", "Celsius");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%6.0f\t\t%6.1f\n", fahr, celsius);
		fahr += step;
	}

	/* The book's version */


	
/*
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%6.0f %15.1f\n", fahr, celsius); //changed the character width from what was present in the book so values fall neatly under the table headings
		fahr = fahr + step;
	}

*/
	



}