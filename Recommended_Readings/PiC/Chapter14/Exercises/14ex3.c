#include <stdio.h>

float f = 1.00;
short int i = 100;
long int l = 500L;
double d = 15.00;

int main(void)
{
	printf("The variables are: \n");
	printf("float f = 1.00\n");
	printf("short int i = 100\n");
	printf("long int l = 500L\n");
	printf("double d = 15.00\n");

	printf("\n");

	printf("f + i = %f. Should give a float \n", f + i); //float
	printf("l / d = %f. Should give a double \n", l / d); //double 
	printf("i / l + f = %f. Should give a float\n", l / d); //float
	printf("l * i = %li. Should give a long int\n", l * i); //long int
	printf("f / 2 = %f. Should give a float\n", f / 2); //float
	printf("i / (d + f) = %f. Should give a double\n", i / (d + f)); //double
	printf("l / (i * 2.0) = %f. Should give a float because of the 2.0\n", l / (i * 2.0)); //float
	printf("l + i / (double) i = %f. Should give a double\n", l + i / (double) i); //double
	
	

}