/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 //This file has an error which I am trying to figure out. 
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

#define     MIN     0

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int p;
    p = binarySearch(value, values, MIN, n-1);

    /* This was linear search
    // TODO: implement a searching algorithm using a linear search

    int i, p;
    if (n <= 0)
    {
        return false;
    }
    
  
    for (i = 0; values[i] != '\0'; i++)
    {
        if(values[i] == value)
        {
            p = 1;
            break;
        }

    else
        p = 0;
    }
    
    if(p == 1)
        return true;

    else
        return false;
    */

    if (p == -1)
        return 0;
    else
        return 1;

}

/**
 * Sorts array of n values.
 Re-write search in such a way that it uses linear search, 
 returning true if value is in values and false if value is not in values. 
 Take care to return false right away if n isn’t even positive.

 TO CONFIRM THE PROGRAM WORKS RUN THE FOLLOWING
 ./generate 1000 50 | ./find 127
 ./generate 1000 50 | ./find 128
 look at the notes for more information
 Best to try some other tests as well, as by running generate with some seed, 
 taking a look at its output, then piping that same output to find, 
 looking for a "needle" you know to be among the "hay".

 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int i, j, min;
    int temp[1];

    //for i = 0 to n - 1
    for (i = 0; i != n - 1; i++)
    {
        min = i;

        for (j = i + 1; j != n; j++)
        {
            //if array[j] < array[min]
            if(values[j] < values[min])
                min = j;
        }

        if (min != i)
        {
            temp[0] = values[min];
            values[min] = values[i];
            values[i] = temp[0]; 
        }
    }

    return;
}

int findMidPoint(int min, int max)
{
    int midpoint = (max + min)/2;

    return midpoint;

}

int binarySearch(int value, int values[], int min, int max)
{
    //if (max < min):
    int midpoint, max_i, min_i, p = 0;
        //return -1
    max_i = max;
    min_i = min;


    if (max_i < min_i)
    {
        p = -1;

    }
  
    else
    {
        midpoint = findMidPoint(min, max);

        if (values[midpoint] < value)
        {
           min_i = midpoint + 1;
           binarySearch(value, values, min_i, max_i);           
        }
        else if(values[midpoint] > value)
        {
            max_i = midpoint - 1;
            binarySearch(value, values, min_i, max_i);  
        }
        else
        {
            p = midpoint;
        }
            

    }

    return p;



}



