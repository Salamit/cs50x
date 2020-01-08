/* Exercise 5 from C Progrogramming 2nd Edition
File 1ex5.c

This program uses the for statement to convert 
Fahrenheit to Celsius starting with 
300 degrees and stopping at 0 degrees F*/

#include <stdio.h>
main()
{
	int fahr;

	printf("%3s\t%s\n", "Fahrenheit", "Celsius");
	for(fahr = 300.0; fahr >= 0.0; fahr -= 30.0)
		printf("%6.0d\t\t%6.1f\n", fahr, (5.0 * (fahr - 32.0)/9.0));

	/* The book's exercise on for loops with formart adjusted to fit the table heads.
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%6.0d\t\t%6.1f\n", fahr, (5.0/9.0) * (fahr - 32)); 
	*/

}