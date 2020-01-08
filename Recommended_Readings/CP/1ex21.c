// Exercise 21 from Chapter 1 of C programming
// File 1ex21.c


//This program 'entab' replaces string of blanks by the minimum
// of tabs and blanks to achieve the same spacing. 

#include <stdio.h>

#define TABINC	8						/* tab increment size	*/

/* replace string of blanks with tabs and blanks				*/
int main()
{
	int c, nb, nt, pos;

	nb = 0; 							/* # of blanks necessary */
	nt = 0;								/* # of tabs necessary	*/
	for (pos = 1; (c = getchar()) != EOF; ++pos)
		if (c == ' ') { 
			if (pos % TABINC != 0)			//if # of spaces is a multiple of TABINC then replace space with blanks 
				++nb;						/* increment # of blanks */
			else {
				nb = 0;					/* reset # of blanks when pos is divisible by TABINC	*/
				++nt;					/* increment by one more tabs 		*/ 
			}

		} 
		else {							// If c is a non blank
			for (; nt > 0; --nt)
				putchar('\t'); 			/* forget the blank(s)	*/
			if (c == '\t')
				nb = 0;
			else
				for ( ; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (TABINC - (pos -1) % TABINC) - 1;
		}
}