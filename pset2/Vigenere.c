/**
 * Pset 2 exercise 1 "Vigenere"
 * caesar.c
 *
 * T.Salami
 * salamidottopeatgmaildotcom
 *
 * Program to encrypt messages using Vigenère's cipher.
 * 
 * 
 * 
 */

 #include <stdio.h>
 #include <cs50.h>
 #include <ctype.h>
 #include <string.h>



 int main(int argc, string argv[])  //must accept a single command-line argument: 
 {
 	string k = argv[1];
    int shift = 0;
    int c = 0;
    int character = 0;
    int n = 0;
   
      //a keyword, k, composed entirely of alphabetical characters. 
    

 	//If your program is executed without any command-line arguments,

    if (argc == 2 )
    {
        n = strlen(k);

        for (int i = 0; i < n; i++)
        {
            if(isalpha(k[i])) 
                {
                    c = 1;                
                }

            else
            {
                printf("Evil!\n");

                c = 0;
                return 1;
                break;
            }
        }
        

        if( c == 1 )
        {
            string plainText = GetString();

            for (int p = 0, i = 0; plainText[p] != '\0'; p++ )
            {
                if (isalpha(plainText[p]))
                {
                   
                    i %= n; 

                    if (isupper(k[i]))
                    {
                        shift = k[i] - 65;
                    }

                    if (islower(k[i]))
                    {
                        shift = k[i] - 97;
                    } 

                    if (isupper(plainText[p]))
                    {
                        character = (((plainText[p] - 65 + shift) % 26) + 65);
                        printf("%c", character);
                    }

                    if (islower(plainText[p]))
                    {
                        character = (((plainText[p] - 97 + shift) % 26) + 97);
                        printf("%c", character);
                    }

                    i++;
                }

                else
                    printf("%c", plainText[p]);

            }
            //convert the character in the plaintext to alpha index

            //shift the converted character by the alpha index of the first keyword

            //print the new ascii value of the shifted plaintext

            printf("\n");

        }
        
    }
    
   
    else
    {

        printf("Evil!\n");

        return 1;
    }
 	
 	//with more than one command-line argument,
 	//or with one command-line argument that contains any non-alphabetical character,
    return 0; 
 }

