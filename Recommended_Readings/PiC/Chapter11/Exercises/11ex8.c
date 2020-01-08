//Program to sort 3 integers into ascending order without using arrays

#include <stdio.h>

/*struct numbers
{
	struct numbers *previous;
	int 			*value;
	struct numbers *next;

}n1, n2, n3, *numberPtr = &n1;
*/

void sort3(int *x1p, int *x2p, int *x3p);

int main(void)
{
	int i1 = 4, i2 = 3, i3 = 2;

	int *i1p = &i1, *i2p = &i2, *i3p = &i3;

	/*

	printf("Enter 3 integers\n");
	printf("integer 1: ");
	scanf("%i", &i1);

	printf("integer 2: ");
	scanf("%i", &i2);

	printf("integer 3: ");
	scanf("%i", &i3);
	*/

	/*

	n1 = (struct numbers) 		{(struct numbers*) 0, &i1, &n2};
	n2 = (struct numbers)		{&n1, &i2, &n3};
	n3 = (struct numbers)		{&n2, &i3, (struct numbers*) 0};

	*/

	printf("Numbers before sort\n");
	printf("%i, %i, %i \n", i1, i2, i3);
	

	sort3(i1p, i2p, i3p);

	printf("Numbers after sort\n");
	printf("%i, %i, %i \n", i1, i2, i3);



	return 0;


}

void sort3(int *x1p, int *x2p, int *x3p)
{
	int min, i = 1;

	while(i != 0)
	{
		i = 0;

		if(*x2p < *x1p)
		{
			min = *x2p;
			*x2p = *x1p;
			*x1p = min;
			i++;
		}

		if (*x3p < *x2p)
		{
			min = *x3p;
			*x3p = *x2p;
			*x2p = min;
			i++;
		}
	}

}

/*
void sort3(struct numbers *structPtr)
{
	//implementing bubble sort
	int i = 0, j, min;

	//if the next entry in the struct is greater than the previous entry
	//switch places
	min = *(structPtr->value);
		while (structPtr != (struct numbers *) 0 )
		{
			if(*(structPtr->value) < *(structPtr->next->value))
			{
				//switch places
				min = *(structPtr->next->value);
				j = *(structPtr->value);
				*(structPtr->value) = min;
				*(structPtr->next->value) = j;
				//counter
				i++;
				//go to the next variable
				structPtr = structPtr->next;

			}	

			//printf("%i\n", list_pointer -> value);
			
		}
		
		structPtr = &n1;
		if(i > 0)
			sort3(numberPtr);




}

*/