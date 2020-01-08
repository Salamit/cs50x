//Program to implement the collatz conjecture

#include <stdio.h>

int *collatz(int n, int *pc );

int main(void)
{
	int c = 0;
	int *pc = &c;
	
	pc = collatz(50, pc);

	printf("%i\n", *pc );

}

int *collatz(int n, int *pc)
{
	
	if (n == 1)
	{
		return pc;

	}

	if((n % 2) == 0)
	{
		(*pc)++;
		collatz(n/2, pc);

	}

	else
	{
		(*pc)++;
		collatz( 3 * n + 1, pc );
	}
		
		return pc;

}