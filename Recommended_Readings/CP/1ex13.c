// Exercise 13 from Chapter 1 of C programming
// File 1ex13.c

// This program prints a histogram of the length of words
// in an input. 

#include <stdio.h>


#define MAXHIST 15      		/* max length of histogram 		*/
#define MAXWORD 11 				/* max length of a word 		*/
#define OUT 0					/* outside a word 				*/
#define IN  1 					/* inside a word 				*/
//#define MAXWORDLEN 11 		/* Solution 1 declarations. Uncomment the '#define part of this line to use solution 1'  */


/* print horizontal histogram 									*/
int main ()
{

	int c, i, j, nc, state;
	int len;					/* length of each bar			*/
	int maxvalue; 				/* maximum value for wl[]		*/
	int ovflow;					/* number of overflow words 	*/
	int wl[MAXWORD];			/* word length counters. Defining an int array with 11 character variables. This is the same as saying int wl[11]			*/

	state = OUT;
	nc = 0;						/* number of chars in a word 	*/
	ovflow = 0; 				/* number of words 				*/

	for (i = 0; i < MAXWORD; ++i) //What is the purpose of this? Does it initialize the array?
		wl[i] = 0;

	printf("Enter a sentence of your choosing\n");
	printf("If you would like, you can copy and paste the following:\n");
	printf("It's a fair bet that if it's fair tomorrow,\n");
	printf("then my fair haired wife and I will head to the\n");
	printf("Spring Fair, which is held in a fair sized park,\n");
	printf("in this fair city of ours and we may win a\n");
	printf("prize in a competion if everyone else plays fair.\n");


	while ((c = getchar()) != EOF) //get a character
	{
		if (c == ' ' || c == '\n' || c == '\t') // if c is a blank, new line or tab
		{
			state = OUT;  // we are outside a word. Question: Why, have lines 38 to 50? Afterall we are counting the number of length of words
			if (nc > 0)  // If the number of characters is above 0. Note: While nc is defined above where is the input for nc as in how does the user change it?
				if (nc < MAXWORD) //if the number of characters is less than the maxword length counter.
				{
					++wl[nc]; // increase the number of elements/number of characters in the array by 1.  
				}
				
				else
				{
					++ovflow; // if nc is greater than the maxword however, increase the overflow by 1
				} 

			nc = 0; //does this reset the number of characters?
		} 
		// The beginning of a new word
		else if (state == OUT) {  //if state is out or better put, if we are not in a word
			state = IN;				// In that case, upon accepting a new character, we are at the start of a new word hence state is in.
			nc = 1;					// and upon accepting a character, the number of characters is 1.
		}

		// inside a word
		else 
		{
			++nc;					// if not outside a word or in a word, increase the number of characters by 1

		}
			
	}
/*
	maxvalue = 0 ; //The max value for the array is 0. Are we initializing maxvalue here?
	for (i = 1; i < MAXWORD; ++i) //Run a for loop until i is 10. Since MAXWORD length counter is 11.
		{
			if (wl[i] > maxvalue) //if the elements in the array is greater than the max number of elements allowed in the array
					maxvalue = wl[i]; //the max amount of elements allowed in the array is the same as the number of elements in the array. 
			}

	for (i = 1; i < MAXWORD; ++i)
	{
		printf("%5d - %5d : ", i, wl[i]); //i refers to the word length while wl[i] is the frequency of its occurence.
		if (wl[i] > 0) {
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;

		}

		else
			len = 0;
		while (len > 0) 
		{
			putchar ('*');
			--len;

		}
		putchar('\n');

	}
	if (ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);

	*/

	// Vertical Histogram

	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];

	for (i = MAXHIST; i > 0; --i) {
		for (j = 1; j < MAXWORD; ++j)
			if (wl[j] * MAXHIST / maxvalue >= i)
				printf(" * ");
			else
				printf("   ");

			putchar('\n');
	} 

	for ( i = 1; i < MAXWORD; ++i)
		printf("%4d ", i);
	putchar('\n');
	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", wl[i]);
	putchar('\n');
	if (ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);


	return 0;
}

