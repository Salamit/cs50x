//Write a pointer version of the sort function from Chapter 8, "Working
// with Functions." Be certain that pointers are exclusively used by the function,
//including index variables in the loops.
//File 8ex14D.c
#include <stdio.h>


// File 8ex13.c
//void sort (int a[], int n, char order);
void sort (int *array, int * const n, char *order);


int main (void)
{
	char order;
	int i;
	int const n = 16;
	int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
					  44, -3, -9, 12, 17, 22, 6, 11 };


	printf("To sort in ascending order input 'a'\n");
	printf("To sort in descending order input 'd'\n");
	scanf("%c", &order);

	int * const arrayEnd = array + n;


	printf("The array before the sort:\n");

	for ( i = 0; i < 16; ++i )
		printf("%5i ", array[i]);

	sort (array, arrayEnd, &order);

	printf("\n\nThe array after the sort:\n");

	for ( i = 0; i < 16; ++i )
		printf("%5i ", array[i]);

	printf("\n");

	return 0;
}

void sort (int *array, int * const n, char *order)
{
	int temp;
	int *tempArray = array;

	if(*order == 'a')
	{
		for ( ; array < n - 1; ++array )
			for ( tempArray = array + 1; tempArray < n; ++tempArray )
				if ( *array > *tempArray ) 
				{
					temp = *array;
					*array = *tempArray;
					*tempArray = temp;
				}
	}

	if(*order == 'd')
	{
		for ( ; array < n - 1; ++array )
			for ( tempArray = array + 1; tempArray < n; ++tempArray )
				if ( *array < *tempArray ) {
					temp = *array;
					*array = *tempArray;
					*tempArray = temp;
				}
	}


}