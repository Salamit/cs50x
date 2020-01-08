/* Exercise 1-7 from C Programming
2nd Edition */

/* This program prints the value of EOF */

#include <stdio.h>
main()
{
	int c;
	c = (getchar() != EOF);
		printf("%d\n", c);



	printf("Press any key\n");
	printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);
	return 0;
}