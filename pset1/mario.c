// Itsa Mario exercise for pset1 from cs50: http://goo.gl/UebylS
// File mario.c


// This program recreates a half-pyramid found at the link 
// above by using hashes for blocks. It first prompts the user 
// the half-pyramid's height, a non-negative integer no greater
// than 23. Should the user fail to provide a non-negative integer
// greater than 23, the user is re-prompted. Upon providing 
// appropriate value, the half-pyramid is build using printf.


#include <stdio.h>
#include <cs50.h>

int i; 
int s; 								/* variable for spaces */
int rn;								/* row number variable */ 
int ha; 							/* variable for hashes */
int hpyrh; 							/* half-pyramid's height */


int main()
{
	
	do 
	{
		printf("Height: ");  	//Using GetInt to get the user's input. 
		hpyrh = GetInt();      //GetInt is a cs50 function, a description of which 
								//can be found here https://goo.gl/I6NuE3 
							

	} while (hpyrh < 0 || hpyrh > 23);	



		

		rn = hpyrh;					// rn is initialized as the value of the pyramid's height (hpyrh), which the user inputted
		for(i = 0; i < hpyrh; i++)	  
		{							  	
									 
									 
										
			

			s = 0;					// initiallize s
			while (s < (rn - 1))	// run the while loop until this condition is met. (rn - 1) is the last row. 
			{
				printf(" ");		//print the space
				s++;				//increment is the updated needed to ensure that the condition is eventually met
									// it prevents a forever loop from happening.
				
			}

			ha = 0;
			while (ha < (i + 2))
			{
				printf("#");
				ha++; 
			}


			printf("\n");			
			rn--;					//The final piece of the puzzle reduces the spaces printed by
									// one compared to the line that preceeded it. 

		}

	



	return 0;
}