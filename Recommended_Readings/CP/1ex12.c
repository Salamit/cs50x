// Exercise 12 from Chapter 1 of C programming
// File 1ex12.c

// This program prints its input one word per line 

#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

main()
{

	int c, state;

	//An answer that I like from clc-wiki.net solution - goo.gl/hWl0d8
	
	state = OUT;

	while (( c = getchar()) != EOF )
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN)
			{
				state = OUT;
				putchar('\n');
			}
		}

		else {
			state = IN;
			putchar(c);
		}
	}

	/* 

	//The C Programming answer book's solution

	while (( c = getchar()) != EOF )
	{

		if (c == ' ' || c == '\t' || c == '\n') //If c is a blank, tab or newline
			{
				if (state == IN)				//If state is equal to in
				{
					putchar('\n');
					state = OUT;
				}
			}

		else if (state == OUT)
		{
			state = IN;
			putchar(c);
		}

		else
			putchar(c);
	}

	*/

	//My solution

	/* 

	while ((c = getchar()) != EOF)
	{
		

		if (c == ' ')
		{
			putchar('\n');
		}

		if (c == '\t')
		{
			putchar('\n');
		}

		else
			putchar(c);
	}
	*/

	return 0;
}