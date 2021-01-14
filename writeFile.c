#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include "readFile.h"
#include "encode.h"
#include "writeFile.h"

void inputFileNameCh2(char filename[][50])
{
     char inputkeyboard[20];
     printf("ENTER THE FILENAME TO WRITE THE ENCODED MESSAGE: \n");
     fgets(inputkeyboard, 20, stdin);
     sscanf(inputkeyboard, "%s", filename[1]);
}
void openWriteOnFile(char filename[][50])
{
    FILE *outfile=NULL;
    outfile=fopen(filename[1], "w");
    if(outfile==NULL)
    {
        printf("Error the file cannot open");
        exit(0);
    }
    printf("Successfully opened and wrote file.\n");
    writeDecodedFile(outfile);
    fclose(outfile);
}
    void writeDecodedFile(FILE *outfile)
    {
          int index=0;
          while(index<codesIndex)
          {
              if(codes[index][0]>=0)
                fprintf(outfile, "%d,%d", codes[index][0], codes[index][1]);
              else if(codes[index][0]==-1)
              fprintf(outfile, "#");
              else
                fprintf(outfile, " ");
              if(index!=codesIndex-1 && (codes[index][1]!=-2 && codes[index+1][0]!=-2))
                  fprintf(outfile, ",");
                index++;
        }
    }