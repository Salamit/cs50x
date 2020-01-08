#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

 
 #define BLOCK  512 
 
 typedef uint8_t  BYTE;
 

 int main(int argc, char *argv[])
 {
    //ensure proper usuage
    if(argc != 2)
    {
        fprintf(stderr, "Usuage: ./recover filename\n");
        return 1;

    } 

    // create file pointer
    char *pfilename = argv[1];

    /* open memory card file */
    //If it isn't able to be opened return 2
    FILE *pmem = fopen(pfilename, "r");
    if (pmem == NULL)
    {
        fprintf(stderr, "Could not open %s\n", pfilename);
        return 2;
    }


    // count parameter
    int jpegCount = 0;
    // holds the rea
    int openedJpeg = 0;
    char filename[50];

    //create an array called buffer of size 512
    
    BYTE buffer[BLOCK];
    
    /*
    BYTE *buffer = malloc(512 * sizeof(BYTE));
    if(buffer == NULL)
        {
            return 3;
        }
    */

    //Provide a JPEG filename
    sprintf(filename, "%03i.jpg", jpegCount);

    //create JPEG file with established filename for writing
    FILE *img = fopen(filename, "w");
    if (img == NULL)
    {
        fclose(pmem);
        fprintf(stderr, "Could not create %s.\n", filename);
        return 3;
    } 


    //read file 
    while(fread(&buffer, 1, 512, pmem) == 512)
    {

        /* find beginning of JPEG */

        // are we at a start of a new JPEG? - first 4 bytes indicate the start of a new JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            /* open a new JPEG */

            // a JPEG file isn't open
            if(openedJpeg == 0)
            {

                openedJpeg = 1;

                //write the bytes to the file
                fwrite(&buffer, 1, 512, img);

            }

            //if a JPEG was already found
            else
            {
                //close previous JPEG
                fclose(img);
                jpegCount++;
                openedJpeg = 0;


                //Provide a new JPEG filename
                sprintf(filename, "%03i.jpg", jpegCount);

                //create a new JPEG file with the established filename for writing
                img = fopen(filename, "w");   
                if (img == NULL)
                {
                    fclose(pmem);
                    fprintf(stderr, "Could not create %s.\n", filename);
                    return 3;
                }

                openedJpeg = 1;

                //write the bytes to the file
                fwrite(&buffer, 1, 512, img);

            }


        }

        //first 4 bytes are not the start of a new JPEG
        else
        {
            //JPEG is not open
            if(openedJpeg == 0)
            {
                //discard the 512 bytes and continue loop

            }

            //JPEG is open
            else
            {
                //write to the current JPEG file
                fwrite(&buffer, 1, 512, img);
            }

        }




    }

    //free memory allocated
    //free(buffer); 

    fclose(img);
    openedJpeg = 0;

    fclose(pmem);


 }