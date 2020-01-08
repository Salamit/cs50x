// Program to define a type FunctionPtr (using typedef) that represents a pointer
// that returns an int and that takes no arguements

#include <stdio.h>

typedef int (*FunctionPtr)(void); 

int add(void);

int x = 2, y = 2;

int add(void)
{
	int sum;

	sum = x + y;

	return sum;

}



int main(void)
{
	FunctionPtr caladd;

	caladd = add;

	printf("result is %i\n", caladd());


	return 0;
}