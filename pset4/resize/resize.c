/*
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Prompts user for a multiple with which to increase the size of 
 * a bitmap.
 *
 * Usage: ./resize [bitmap to be altered] [new bitmap file name] 
 *
 */


       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines in input file. 
    int padding_I = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //User given number
    int n;
    printf("Provide a number\n");
    scanf("%i", &n);

    //Store existing width and height in temp variables
    LONG OldWidth = bi.biWidth; 
    LONG OldHeight = bi.biHeight;

    //Update Outfile's header info
    bi.biWidth *= n;
    bi.biHeight *= n;

    // determine padding for scanlines in output file. 
    int padding_O = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding_O) *abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);



    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);



    //resizing horizontally
    // iterate over infile's scanlines
    for (int i = 0, height = abs(OldHeight); i < height; i++)
    {
        //temp array
        RGBTRIPLE *pixels = malloc(bi.biWidth * sizeof(RGBTRIPLE));
        if(pixels == NULL)
        {
            return 5;
        } 

        //count variable
        int count = 0;

        for (int j = 0; j < OldWidth; j++)
        {

            // temporary storage
            RGBTRIPLE triple;




            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //place each pixel in an array n times
            int x = n;
            while(x > 0)
            {
                pixels[count] = triple;
                count++;
                x--;
            }
            
        }

        // skip over padding, if any
        fseek(inptr, padding_I, SEEK_CUR);

        int x = n;
        while(x > 0)
        {
            for (int l = 0; l < bi.biWidth; l++)
            {
                RGBTRIPLE triple;
                triple = pixels[l];
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

            //Put in the padding

                   
            for (int k = 0; k < padding_O; k++)
            {
                fputc(0x00, outptr);
            }

            x--;
        }

        //free memory allocated
        free(pixels);

    }



    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
