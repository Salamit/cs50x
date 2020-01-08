/* Exercise 9 of chapter 1 from C Programming
2nd Edition.
File name 1ex9.c */

#include <stdio.h>

/* This program copies the input to the output 
and replaces each string of one or more blanks by a single blank 
There are three separate copy programs in this file. The first uses
a while loop. The second uses the for loop and the last 
uses the do...while loop. The for and while loops
have been commented out. */

main()
{
	int c, lastc;

	
	



/*
	for (c = 0; ((c = getchar()) != EOF); c++)

	{
		

		if (c != ' ')
		
			putchar(c);

		if (c == ' ')    		//This contraption from line 26 to line 31
		{						// instructs the machine that 'Hey blockhead'
			if (lastc != ' ') 	// check that a character is not a blank
				putchar(' ');	// If it is and if the character before it
		}						// was a blank then put only one blank
		lastc = c; 				// Line 31 tells the machine that c
	

	}	*/

	/*while ((c = getchar()) != EOF)
	{
		if (c != ' ')
		
			putchar(c);

		if (c == ' ')
		{
			if (lastc != ' ')
				putchar(' ');
		}
		lastc = c;
	} */

	do {

		c = getchar();

		if (c != ' ')
			putchar(c);

		if (c == ' ')
		{
			if (lastc != ' ')
				putchar(' ');
		}

		lastc = c;
	} while (c != EOF);
		
	return 0;
}