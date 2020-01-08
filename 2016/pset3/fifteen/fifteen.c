/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d, tileTotal, largest_tile, tempTileCount;
//location of the blank
int space_i, space_j;
//location of the given tile
int tile_i, tile_j;
//2d array declaration. 
                   


// prototypes
void clear(void);
void greet(void);
void init(int n, int board[n][n]);
void draw(int n, int board[n][n]);
bool move(int tile, int n, int board[n][n]);
bool won(int n, int board[n][n]);
void switch_space_and_digit(int n, int board[n][n]);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    int board[d][d];

    // initialize the board
    init(d, board);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(d, board);

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won(d, board))
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile, d, board))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(int n, int board[n][n])
{
    int i, j;
    //Total number of tiles     
    tileTotal = d * d;
    
    largest_tile = tileTotal - 1;
    //Count of visible tiles
    tempTileCount = largest_tile; 
   

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if((n % 2) == 0) 
            {
                board[i][j] = tempTileCount;
                tempTileCount -= 1; 

                //if (i == (n - 1) && j == (n - 3))
                board[n - 1][n - 3] = 1;
                board[n - 1][n - 2] = 2;
                board[n - 1][n - 1] = 0;

            }

            else
            {
                board[i][j] = tempTileCount;
                tempTileCount -= 1; 
            }
            
        }
        
    }

    //location of the underscore
    space_i = n - 1;
    space_j = n - 1;
    
    //board[space_i][space_j] = '_';

}

/**
 * Prints the board in its current state.
 */
void draw(int n, int board[n][n])
{
    // TODO
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(board[i][j] == 0)
                printf(" _ " );

            else
                printf("%2i ", board[i][j]);

        }
        printf("\n\n");
    }
    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile, int n, int board[n][n])
{
    int i = 0; 
    int j = 0;
    int result = false;


    // Given tile
    // Find the location of tile
    for(i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
            if(board[i][j] == tile)
            {
                tile_i = i; 
                tile_j = j;


                //You would have to draw a board to fully understand this but basically, 
                //a boradering tile will always be one of the following dimensions 
                //]space_i][space_j - 1] || ]space_i][space_j + 1] || [space_i -1][space_j] || [space_i + 1][space_j]
                //where space_i is the i cordinates of the empty tile and space_j is the j cordinate of the empty tile
                if(tile_i == space_i)
                {
                    if(tile_j == space_j - 1 || tile_j == space_j + 1)
                    {
                        switch_space_and_digit(d, board);
                        result = true;
                        
                    }           
                }

                if(tile_i == space_i - 1 || tile_i == space_i + 1) 
                {
                    if(tile_j == space_j)
                    {
                        switch_space_and_digit(d, board);
                        result = true;
                    
                    }                    
                }
                

            }
            
            if(result == true)
                break;
        }

        if(result == true)
            break;

    }


    //Does tile border empty space?
/*
    //i = j = 0;

    while((i || j ) < d)
    {   //assuming 
        if((tile_i == space_j) && (tile_j == ((space_j - 1) || (space_j + 1))))
        {
            switch_space_and_digit();     
            result = true;

        }

        if((tile_i == ((space_j - 1) || (space_j + 1))) && (tile_j == space_j))
        {
            switch_space_and_digit();
            result = true;

        }

        else
            result = false;

        i++
    }
    */
    

  /*  
    for(int i = 0; i < d; i++ )
    {
        for(int j = 0; j < d; j++)
        {
            


        }
    }
    */

    return result;


}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(int n, int board[n][n])
{
    int result = false;
    tempTileCount = 1;
    
    for(int i = 0; i < d; i++ )
    {
        for(int j = 0; j < d; j++)
        {
            /*if(tempTileCount == d)
            {
                result = true;
                break;
            }*/


          if(board[i][j] == tempTileCount)
          {
            tempTileCount += 1;
            result = true;
            if(tempTileCount == (d * d - 1))
                break;

          }

          else
          {
            result = false;
            break;
          } 
            


          /*  if(result == true && (i == (n - 1)) && (j == (n - 1)))
            {    
                if(board[n-1][n-1] == '_')
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
            */    
        } 
        if(result == false)
            break;
    }
    return result;
}

//switch the underscore and the digit
void switch_space_and_digit(int n, int board[n][n])
{
    int temp_s = 0;
    int temp_i = 0;
    int temp_j = 0;
    int temp_d = 0;
     
    //put the underscore in a temp variable
    temp_s = board[space_i][space_j];
    //save the tile in a temp variable
    temp_d = board[tile_i][tile_j];


    //Save the old values of i and j in a temp variable
    temp_i = space_i;
    temp_j = space_j;
    //the new values for i and j are
    space_i = tile_i;
    space_j = tile_j;
    //the new values of i and j for the tile are
    tile_i = temp_i;
    tile_j = temp_j;
    
    //put the digit in its new location
    board[tile_i][tile_j] = temp_d;

    //put the underscore in its new location
    board[space_i][space_j] = temp_s;

    
}

