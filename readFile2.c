#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Strok.h"
#include "readFile.h"
#include "readfile2.h"
char encodedtext[5000][75];
int encodedtextwordcount=0;

void inputFileNameCh3(char filename[][50])
{         char inputKeyboard[20];
          printf("ENTER THE FILE NAME CONTAINS ENCODED MESSAGE FOR DECODING: \n");
          fgets(inputKeyboard, 20, stdin);
          sscanf(inputKeyboard, "%s", filename[2]);
}
void openreadFromFileCh3(char filename[][50])
{
      FILE *infile;
      infile=fopen(filename[2], "r");
      if(infile==NULL)
      {
          printf("Error the file can not open");
          exit(0);
      }
      printf("Successfully opened and read the file\n");
      readDecodedFil(infile, encodedtext);
     // printEncodedWords(encodedtext);
      fclose(infile);
}

    void readDecodedFil(FILE *infile, char encodedtext[][75])
    {
        int index=0;
        while(fscanf(infile, "%s", encodedtext[index])!=EOF)
        {
            encodedtextwordcount++;
            index++;
        }
    }
        void printArray(char array[])
        {   int i=0;
            while(array[i]!='\0')
             printf("%c", array[i++]);
              printf("\n");

        }
        void printEncodedWords(char encodedtext[][75])
        {
              int index=0;
              while(index<encodedtextwordcount)
              {
                  printf("%s", encodedtext[index]);
                  index++;

              }
        }