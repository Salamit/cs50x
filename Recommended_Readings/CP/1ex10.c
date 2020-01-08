// Exercise 10 from Chapter 1 of C programming
// File 1ex10.c

// This program copies the input to the output. It also
// replaces each tab with \t, each backspace with \b
// and each backslash with \\.


#include <stdio.h>

int c, d;

main()
{
	while ((c = getchar()) != EOF)

	{
		
		if (c == '\b'){
			printf("\\b");
			

		}

		if (c == '\t'){
			printf("\\t");
			
		}

		if (c == '\\'){
			printf("\\\\");
			
		}

		if (c != '\b' || c != '\t' || c != '\\' )
			putchar(c);


		/*

		//First solution
		d = 0;
		if (c == '\b'){
			printf("\\b");
			d = 1;

		}

		if (c == '\t'){
			printf("\\t");
			d = 1;
		}

		if (c == '\\'){
			printf("\\\\");
			d = 1;
		}

		if (d == 0)
			putchar(c);

			*/



		//Second solution

		/*
		d = 0;
		if (c == '\t')
			{
				putchar('\\');
				putchar('t');
				d = 1;
			}

		if (c == '\b')
			{
				putchar('\\');
				putchar('b');
				d = 1;
			}

		if (c == '\\')
			{
				putchar('\\');
				putchar('\\');
				d = 1;
			}

		if (d == 0)
			putchar(c);

		*/



		// Third solution

		/*if (c == '\t')
			printf("\\t");

		if (c == '\b')
			printf("\\b");

		if (c == '\\')
			printf("\\\\");

		if (c != '\t') 
			if (c != '\b') 
				if (c != '\\')
					putchar(c);*/
	}
	
	return 0;


			 
}