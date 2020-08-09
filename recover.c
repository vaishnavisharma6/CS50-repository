#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>




typedef uint8_t  BYTE;

int main(int argc , char *argv[])
{
    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s image\n", argv[0]);
        return 1;
    }

    //define buffer as a block of 512 bytes
    BYTE buffer[512];

    //declare other variables
    int file_counter = 0;   //count number of JPEG file to be used for sprintf
    char *filename = malloc(8);
    FILE *img;  //innitiate file pointer

    // open input file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    while (fread(&buffer, sizeof(BYTE), 512, inptr) ==512)
    {
        //using bitwise to check the first 4 bytes of the buffer block
        if (buffer[0] == 0xff &&
        buffer[1] == 0xd8 &&
        buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03d.jpg", file_counter);
            img = fopen(filename, "w");  //where segregated JPEG will live
            fwrite(&buffer, sizeof(BYTE), 512, img);
            file_counter ++ ;



        }

        if (file_counter > 0)
        {
            img = fopen(filename, "a");     //append that buffer block to current file with filename
            fwrite(&buffer, sizeof(BYTE), 512, img);
            fclose(img);
        }
    }
    free(filename);
    fclose(inptr);


    return 0;





}
