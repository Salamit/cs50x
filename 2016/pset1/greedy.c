// Time for Change exercise for pset1 from cs50: http://goo.gl/MLYo8g
// File greedy.c

/* This program first asks the user how much change is owed 
and then spits out the minimum number of coins
with which said change can be made. */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

float input;
int change; 						/* change owed 			*/
int qc;								/* # of quarters needed */
int dc;								/* # of dimes needed 	*/
int nc;								/* # of nickels needed 	*/
int pc; 							/* # of pennies needed 	*/
int c = 0;							/* # of coins 		*/ 
int rem;							/* change remaining */
										

int main()
{
	do {
		
		printf("O hai! How much change is owed?\n");
		input = GetFloat();
		
		//input = GetFloat("O hai! How much change is owed? \n")
	} while (input <= 0);

	change = roundf(input * 100);	//change the data type to float here to 
									// to prevent it being truncated. 
									//If this isn't done, then 

	if((change/QUARTER) >= 1)
	{
		qc = change/QUARTER;		//I want the data type to be int here to truncate
		change %= QUARTER;			//has to be an int data type
		c += qc;					//has to be an int data type here

	}

	

	if((change/DIME) >= 1)
	{
		dc = change/DIME;
		change %= DIME;
		c += dc;

	} 

	

	if((change/NICKEL) >= 1)
	{
		nc = change/NICKEL;
		change %= NICKEL;
		c += nc;

	} 

	

	if((change/PENNY) >= 1)
	{
		pc = change/PENNY;
		change %= PENNY;
		c += pc;

	} 

	printf("%d\n", c);

	return 0;

}

