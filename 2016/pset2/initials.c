/**
 * Pset 2 exercise 1 "Initializing"
 * initials.c
 *
 * T.Salami
 * salamidottopeatgmaildotcom
 *
 * Prompts the user for their name and
 * then outputs their initials in uppercase with no spaces or periods
 * followed by a newline
 * 
 */

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>


int main(void)
{

    int i = 0;

    string userName = GetString();
    
    if (userName[0] >= 'a' && userName[0] <= 'z') 
    {
        printf("%c", toupper(userName[0]));
        i++;
        
    }
    
    else if (userName[0] >= 'A' && userName[0] <= 'Z') 
    {
        printf("%c", userName[0]);
        i++;
        
    }
    
    for (  ; userName[i] != '\0' && ((userName[i] >= 'a' && userName[i] <= 'z') 
    || (userName[i] >= 'A' && userName[i] <= 'Z') || userName[i] == ' ') ; i++)
    {
        if (userName[i] == ' ')
        {
            printf("%c", toupper(userName[i + 1])); //this one line, eliminates the need for lines 47 to 59
            /*
            i++;
            if (userName[i] >= 'a' && userName[i] <= 'z')
            {
                printf("%c", toupper(userName[i]));
                
            }
            
            else
            {
                printf("%c", userName[i]);
                
            }
            */
        }
        
    }
    printf("\n");
    
    return 0;
    
}




