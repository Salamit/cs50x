/**
 * Pset 2 exercise 1 "Caesar"
 * caesar.c
 *
 * T.Salami
 * salamidottopeatgmaildotcom
 *
 * Program to encrypt messages using Caesar's cipher.
 * Program accepts only a single command-line argument: non-negative integer
 * 
 * 
 */
/*
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
	//accept a single command-line argument: non-negative integer
	int n = GetInt();

	//if no command-line argument and if more than one command-line argument
	if ((n != NULL) || (n < 0 || n > 9 ))
	{
		//yell at the user
		printf("You bad person! Your free reign has come to an end.\n");

		// return a value of 1
		return 1;
	}

	
}
*/

/**
 * string-1.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Prints a string, one character per line.
 *
 * Demonstrates error checking.
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get line of text
    string s = GetString();

    // print string, one character per line
    if (s != NULL)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            printf("%c\n", s[i]);
        }
    }
}