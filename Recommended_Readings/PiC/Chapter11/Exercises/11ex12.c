//Given the following declarations 

#include <stdio.h>

int main()
{
	char *message = "Programming in C is fun";
	char message2[] = "You said it\n";
	char *format = "x = %i\n";
	int  x = 100;

	printf ("Programming in C is fun\n"); 
	printf ("%s", "Programming in C is fun\n"); 
	printf ("%s\n", message);
	printf (message); /*This isn't safe according to the compiler*/
	printf("\n");

	printf ("You said it\n"); 
	printf ("%s", message2); 
	//printf (message2); /*This isn't safe aswell according to the compiler*/
	printf ("%s", &message2[0]);

	printf ("said it\n"); 
	//printf (message2 + 4); 
	printf ("%s", message2 + 4); 
	printf ("%s", &message2[4]);

	printf ("x = %i\n", x); 
	printf (format, x);
}
