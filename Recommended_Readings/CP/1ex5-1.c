/* Exercise 5 extended from C Progrogramming 2nd Edition
File 1ex5-1.c

This program extends ex5 which uses the for statement to convert 
Fahrenheit to Celsius starting with 
300 degrees and stopping at 0 degrees F
The difference between this program and ex5 
is the use of symbolic constants
*/

#include <stdio.h> 

#define LOWER 300
#define UPPER 0
#define STEP 20

main()
{
	int fahr;

	for(fahr = LOWER; fahr >= UPPER; fahr -= STEP )
		printf("%6.0d\t\t%6.1f\n", fahr, (5.0 * (fahr - 32.0)/9.0));
}