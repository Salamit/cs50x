#include <stdio.h>

int main(void)
{
	int n, x, width, length;
	x = width = length = 2;

	/*printf("Provide the dimension\n");
	scanf("%i", &x);

	width = length = x;
	*/

	int array[2][2] = {
						{'p', 'p'},
						{'p', 'p'},
					};


	printf("value?\n");
	scanf("%i", &n);

	for(int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			array[i][j] = 'p';
		}

		printf("\n");
	}


	for(int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c ", array[i][j]);
		}

		printf("\n");
	}

	int width2 = n * width;
	int length2 = n * length;

	int array2[length2][width2];
	int i2 = 0; 
	int j2 = 0;


	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//print whatever is in the first box x times
			int x = n;
			while(x > 0)
			{
				printf("%c ", array[i][j]);
				x--;
					
			}
			


			
		}
		printf("\n");
	
	}

	printf("demar\n");

	int j = 0;
	int i = 0;


		for(i2 = 0; i2 < length2; i2++, i++)
			{ 
				
				for(j2 = 0; j2 < width2; j2++, j++)
				{
					x = n;
					while(x > 0)
					{
						array2[i2][j2] = array[i][j];
						j2++;
						x--; 

					}
					j2--;
					
				}
			} 


		for(i2 = 0; i2 < length2; i2++)
			{ 
				
				for(j2 = 0; j2 < width2; j2++)
				{

					printf("%c ", array2[i2][j2]);
	
				}

				printf("\n");
			} 

	return 0;



}