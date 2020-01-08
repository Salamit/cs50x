/* Exercise 1-8 from C programming 2nd Edition 
File 1ex8.c
*/

#include <stdio.h>

/* This program counts the number of 
blanks, tabs and newlines in a program.
There are three separate counting programs. The first uses
a while loop. The second uses the for loop and the last 
uses the do...while loop. The while and do...while loops
have been commented out. */

main()
{

	int c, b, t, nl;
	b = 0;					// Number of blanks
	t = 0;					// Number of tabs 
	nl = 0;					//Number of newlines

	
/*
	while ((c = getchar()) != EOF)
	{

		if (c == '\n')
			++nl;
	
		
		else if (c == ' ')

			++b;
		


		else if (c == '\t')
		
			++t;

		printf("There are %d newlines, %d backspaces and %d tabs\n", nl, b, t);
	}

*/
	/*	for (c = 0; ((c = getchar()) != EOF); c++)
		{
			if (c == ' ')
				++b;
			if (c == '\n')
				++nl;
			if (c == '\t')
				++t;

			printf("There are %d newlines, %d backspaces and %d tabs\n", nl, b, t);

		}

	*/


		do {

			c = getchar();

			printf("There are %d newlines, %d backspaces and %d tabs\n", nl, b, t);

			if (c == ' ')
				++b;
			if (c == '\n')
				++nl;
			if (c == '\t')
				++t;
			//else
				//printf("You haven't pushed eiher the Backspace, Tab or Enter key\n");
		
		} while (c != EOF);

	}
		
		return 0;
}
	


		
