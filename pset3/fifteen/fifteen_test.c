#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


int d = 3;
int n = 3;

int board[3][3] = {
				  
				  { 1, 2, 3 }, 
				  { 4, 5, 6 }, 
				  { 7, 8, 9 }
				
				};
int n;
int main(void)
{
	int i, j;
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
            if(i == 2 && j == 2)
                printf(" _ " );

            else
                printf("%2i ", board[i][j]);

        }
        printf("\n\n");
    }

    bool result = false;
    int tempTileCount = 1;
    
    for(int i = 0; i < d; i++ )
    {
        for(int j = 0; j < d; j++)
        {
            if(result == true && (i == (n - 1)) && (j == (n - 1)))
            {    
                if(board[n-1][n-1] == 9 )
                    {
                    	result = true;
                		break;
                	}

            }

            if(i < (d - 1) || j < (d - 1))
            	{
            		if(board[i][j] == tempTileCount)
            		{
                		result = true;
                		tempTileCount += 1;
            		}
            	}

            else
            {
                result = false;
                tempTileCount = 1;
                break;

            }
                
        } 
        if(result == false)
            break;
    }
    
    if(result == true)
    {
    	printf("Win\n");
    }

    else
    	printf("Lost\n");

}