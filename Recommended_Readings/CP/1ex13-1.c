

/* 1.6 of from Chapter 1 of C Programming 2nd Edition
File 1ex13-1.c */

// This program counts the number of occurences of each digit of white
// space characters (blank, tab, newline), and of all other characters.

#include <stdio.h>

/* count digits , white space, others */

int main()
{
	int c, i, nwhite, nother;
	int ndigit[10]; // an array ndigit of 10 integers is declared here.

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c -'0'];

		else if (c == ' ' || c == '\n' || c== '\t')
			++nwhite;
		else
			++nother;

	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf("%d", ndigit[i]);


	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;


}