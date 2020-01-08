// Program to change example 6 from Chapter 10 of Programming in C, 3rd Edition
// to use a character pointer instead of an array
// File 11ex8.c

// Reading lines of data

#include <stdio.h>

void readLine (char *lineP);


/*
int main (void)
{
	int i;
	char *lineP = "c";
	

	for (i = 0; i < 3; ++i )
	{
		readLine (lineP);
		printf("%s\n\n", lineP);
	}

	return 0;
}
*/

int main (void)
{
	int i;
	char line[81];
	void readLine (char buffer[]);

	for (i = 0; i < 3; ++i )
	{
		readLine (line);
		printf("%s\n\n", line);
	}

	return 0;
}

// Function to read a line of text from the terminal 

void readLine (char *lineP)
{
	char character;
	//int i = 0;

	do 
	{
		character = getchar ();
		*lineP = character;
		++lineP;

	}
	while  (character != '\n' );

	*lineP = '\0';
}