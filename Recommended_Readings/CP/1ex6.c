/* Exercise 1-6 from C Programming 2nd Edition
File 1ex6.c  */

/* This program verifies that 
the expression getchar() != EOF is 0 or 1.
*/

# include <stdio.h>

main()
{
	int c;

	c = getchar() != EOF;
	printf("%d\n", c);

}

