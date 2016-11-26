// Smart Water exercise for pset1 from cs50: http://goo.gl/sR0sYq
// File water.c


//This program prompts the user for the length of his or her shower 
//in minutes(as a positive integer). It then prints the equivalent 
//number of bottles of water (as an integer).

#include <stdio.h>
#include <cs50.h>

#define OZPERMIN 192				/* Amount of water in ounces per minute spat by a shower */
#define BTLINOZ   16				/* 1 bottle of water in ounces 							*/


int main()
{

int mininsh; 						/*  variable for minutes in shower */
int btlinsh;						/*  bottles of water used in a shower */



printf("minutes: ");
mininsh = GetInt();   
btlinsh = (mininsh * OZPERMIN) / BTLINOZ;
printf("bottles: %d\n", btlinsh);

return 0;


} 
