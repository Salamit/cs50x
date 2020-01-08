// Program for a function called monthName that takes as its argument 
// a value of type enum month and returns a pointer to a character string
// containing the name of the month

#include <stdio.h>

enum month { january = 1, february, march, april, may, june, 
		july, august, september, october, november, december } aMonth;


char *monthName(enum month number);

char *monthName(enum month number)
{
	char 		*message;

	switch (aMonth ){
		case january:
			message = "January";
			break;
		case february:
			message = "February";
			break;
		case march:
			message = "March";
			break;
		case april:
			message = "April";
			break;
		case may:
			message = "May";
			break;
		case june:
			message = "June";
			break;

		case july:
			message = "July";
			break;
		case august:
			message = "August";
			break;
		case september:
			message = "September";
			break;
		case october:
			message = "October";
			break;
		case november:
			message = "November";
			break;
		case december:
			message = "December";
			break;
		
		default:
			message = "bad month number\n";
			break;

	}

	return message;


}

int main(void)
{
	//take the digit of the month in question
	printf("Enter month number: ");
	scanf("%i", &aMonth);

	//print it out
	printf("%s\n", monthName(aMonth));



	return 0;


}