// Exercise 18 from Chapter 1 of C programming
// File 1ex18.c

/* This program removes trailing blanks and tabs from 
line of input, and deletes entirely blank lines. */


#include <stdio.h>
#define MAXLINE 1000 				/* maximum input line size		*/

int getlines(char line[ ], int maxline);
int removes(char s[ ]);

/* remove trailing blanks and tabs, and delete blank lines */
int main()
{
	char line[MAXLINE];				/* current input line 			*/

	while (getlines(line, MAXLINE) > 0)
		if (removes(line) > 0)
			printf("%s", line);

	return 0;
}

/* remove trailing blanks and tabs from character string s */
int removes(char s[ ])
{
	int i;

	i = 0;
	while (s[i] != '\n')		/* find newline character			*/
		++i;
	--i;						/* back off from '\n'				*/

	if (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if (i >= 0) {				/* is it a nonblank line?			*/		
		++i;
		s[i] = '\n'; 			/* put newline character back		*/
		++i;
		s[i] = '\0';			/* terminate the string				*/
	}
	return i;
}
/* getlines: read a line into s, return length */
int getlines(char s[ ], int lim)
{
	int c, i, j;

	j = 0;
	for (i=0; (c = getchar()) != EOF && c!= '\n'; ++i) //'\n' signifies end of input and kickstarts the if condition below

		if (i < lim-2) {
			s[j] = c;
			++j;
		}

	if (c == '\n') {
		s[j] = c;
		++j;
		++i;
	}

	s[j] = '\0';
	return i;
} 