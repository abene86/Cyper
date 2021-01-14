#include<stdio.h>
#include<stdlib.h>
#include "Strok.h"
char filename[3][50];

void inputFileName(char filename[][50])
{        char inputKeyboard[20];
          printf("Please Enter the name of cypher text: \n");
          fgets(inputKeyboard, 20, stdin);
          sscanf(inputKeyboard, "%s", filename[0]);
}
void openreadFromFile(char filename[][50])
{
      FILE *infile;
      infile=fopen(filename[0], "r");
      if(infile==NULL)
      {
          printf("Error the file can not open");
          exit(0);
      }
      printf("Successfully opened and read the file\n");
      readEleStringsholder(infile, stringsholder);
      //this method can be found in Strok.c source file
      fclose(infile);
}
