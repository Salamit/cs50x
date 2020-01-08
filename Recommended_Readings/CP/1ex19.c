// Exercise 19 from Chapter 1 of C programming
// File 1ex19.c

/* This program reverse(s) the character string s. Use it to
write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000				/* maximum input line size		*/

int getlines(char line[ ], int maxline);
void reverse(char s[ ]);

/* reverse input lines, a line at a time							*/

int main()
{
	char line[MAXLINE];				/* current input line 			*/

	while (getlines(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}
}

/* reverse: reverse sting s 									*/
void reverse(char s[ ])
{
	int i, j;
	char temp;

	i = 0;
	while (s[i]  != '\0')			/* find the end of string s   */
		++i;
	--i; 							/* back off from '\0'			*/
	if (s[i] == '\n')
		--i; 						/* leave newline in place. New string isn't changed here. To change the new string, one would need to change it as one would do normally when changing an array	*/

	j = 0;							
	while (j < i) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		}

}


/* getlines: read a line into s, return length */
int getlines(char s[ ], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c!= '\n'; ++i)

		if(i < lim-2) {
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


