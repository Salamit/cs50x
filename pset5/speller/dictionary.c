/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

#define MAX		27

typedef struct node
{
	bool is_word;
	struct node *children[MAX];
	
}node;

node *root, *travP, *nodeP;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    //for letter in word
    for(int word = 0; word != '\0'; ++word)
    {
        printf("%d\n", word);
    }

    //go to the corresponding element in children

    //if NULL, word is mispelled

    //if not NULL, move to next letter

    //Once at end of input word

    //check if is_word is true
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{	
    int c;

	//open dictionary file
	FILE *dicp = fopen(dictionary, "r");
	//check for Null value
	if (dicp == NULL)
	{
		printf("Could not open dictionary %s\n", dictionary);
		return 1;
	}
	//int a;

	//pointer to the top of the trie
	node *root = malloc(MAX * sizeof(node));
	if(root == NULL)
        {
            return 2;
        }

    travP = root;

    //for every dictionary word, iterate through the trie
    for(c = fgetc(dicp); c != EOF; c = fgetc(dicp))
    {
    	//if LF is hit, set word to true

        if (isalpha(c) || (c == '\''))
        { 

            //Each element in children corresponds to a different letter

            if (c == '\'')
            {
                c = 26;
            }

            //convert a to the equivalent ascii value which will serve as the index 'c' in the array children
            else
            {
                c = tolower(c);
                c = c - 97;
            }
            
        
            //printf("%c\n", c);
        
            //check if children[c] is null  
            if (travP->children[c] == NULL)
            {
                //if children[c]== NULL, malloc a new node.
                node *nodeP = malloc(MAX * sizeof(node));
        
                //have children[c] point to the new node
                travP->children[c] = nodeP; //Is this correct?
        
                //go down to that block of memory
                travP = travP->children[c];
        
                //I might need a recursive function. 
            
            }
        
            else
            {
                //if not NULL move to new node and continue
                travP = travP->children[c];
            }
        }
        
        //if at end of word, set is_word to true
        else
        {
            travP->is_word = 1;
            travP = root;
        }



    }

    //Free all malloced memory
    //free(nodeP);
    //free(root);
		
    fclose(dicp);

    //return true if load was successful
    if(c == EOF)
        return true;

    //return false if load was unsuccessful
    else
        return false;

    
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    free(nodeP);
    free(root);
    // TODO
    return false;
}
