// Exercise 20 from Chapter 1 of C programming
// File 1ex20.c

// This program replaces tabs in the input with the proper number 
//blanks to space to the next tab stop. It assumes a fixed set of 
// tab stops every n columns.


#include <stdio.h>

#define TABINC 8 								/* tab increment size				*/
int main()
{
	int c, nb, pos;

	nb = 0; 									/* number of blanks necessary		*/
	pos = 1;									/* position of character in line	*/
	while ((c = getchar()) != EOF) {
		if (c == '\t') {						/* tab character					*/
			nb = TABINC - (pos - 1) % TABINC; 	/* calculates the number of blanks necessary */	
			while (nb > 0)	{
				putchar(' ');
				++pos;
				--nb;
			}

		} else if (c == '\n')  { 				/* newline character */	
			putchar(c);
			pos = 1;
		} else {								/* all other characters */
		putchar(c);
		++pos;	
		}
	}	
}