/**
 * Pset 2 exercise 2 "Caesar"
 * caesar.c
 *
 * T.Salami
 * salamidottopeatgmaildotcom
 *
 * Program to encrypt messages using Caesar's cipher.
 * Program accepts only a single command-line argument: non-negative integer
 * 
 * 
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    int character = 0;
    


    if (argc == 2)
    {
        int k = atoi(argv[1]);

        string plainText = GetString();


        for (int i = 0; plainText[i] != '\0'; i++)
        {
            if (isalpha(plainText[i]))
            {
                if (isupper(plainText[i]))
                {
                    character = (((plainText[i] - 65 + k) % 26) + 65);
                    printf("%c", character);

                }

                if (islower(plainText[i]))
                {
                    character = (((plainText[i] - 97 + k) % 26) + 97);
                    printf("%c", character);
                }

            }
                


            else
                printf("%c", plainText[i]);


        }
        
    }

    else
    {
        printf("You bad person! Your free reign has come to an end.\n");
        
        return 1;
       
    }

    printf("\n");
    return 0;
}