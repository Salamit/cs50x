/* Not understanding whtat 'character width is' as in this example %6d, I will use this to testing the concept of character width */

#include <stdio.h>
main()
{
	printf("%1d\n", 55);
	printf("%2d\n", 55);
	printf("%3d\n", 55);
	printf("%4d\n", 55);
	printf("%5d\n", 55);
	printf("%6d\n", 55);

	printf("%6d %1d\n", 55, 55);
	printf("%6d %2d\n", 55, 55);
	printf("%6d %3d\n", 55, 55);
	printf("%6d %4d\n", 55, 55);
	printf("%6d %5d\n", 55, 55);
	printf("%6d %6d\n", 55, 55);



}