/**
 * Pset 2 exercise 1 "Initializing"
 * initials.c
 *
 * T.Salami
 * salamidottopeatgmaildotcom
 *
 * Prompts the user for their name and
 * then outputs their initials in uppercase with no spaces or periods
 * followed by a newline
 * 
 */

#include <stdio.h>
#include <cs50.h>

//function declaration

//void initial(char userName[]);

int main(void)
{
	char s[20];
	int c = 0;
	int i = 0;

	printf("What is your name?\n");
	string userName = GetString();

	
	if (userName[0] >= 'a' && userName[0] <= 'z') 
		{
				//alphabetize the first initial
			s[0] = userName[0] - 32;
			c++;
			i++;

		}

	else if (userName[0] >= 'A' && userName[0] <= 'z') 
		{
			s[0] = userName[0];
			c++;
			i++;
		}
		

	for (  ; userName[i] != '\0' && ((userName[i] >= 'a' && userName[i] <= 'z') || (userName[i] >= 'A' && userName[i] <= 'Z') || userName[i] == ' ') ; i++ )
	{
		//get string[0]
		if (userName[i] == ' ')
		{
			i++;
			if (userName[i] >= 'a' && userName[i] <= 'z') 
			{
				//alphabetize the first initial
				s[c] = userName[i] - 32;
				c++;
				
			}

			else
			{
				s[c] = userName[i];
				c++;
			}
				

		}


	}

	
	printf("%s", s);

	printf("\n");
	

	return 0;
}




