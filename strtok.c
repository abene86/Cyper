#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "Strok.h"
char stringsholder[5000][15];
int wordcount=0;
void  readEleStringsholder(FILE *infile, char stringsholder[][15])
// read word by word from a text. converts upper case letter to lower. then counts the number of word.
{
        int dictIndex=0;
         while(fscanf(infile, "%s", stringsholder[dictIndex])!=EOF)
       {
           ++wordcount;
           convertStringEleSmall(stringsholder[dictIndex]);
          // printf("%d: %s \n", wordcount-1, stringsholder[dictIndex]);
           dictIndex++;
       }
}
    void convertStringEleSmall(char string[])
    {
            int index=0;
            while(string[index]!='\0')
                {
                     if(string[index]>=65 && string[index]<=90)
                         string[index]=tolower(string[index]);
                     index++;
                }
    }
    void clearstringsholder(char stringsholder[][15], int numberWords)
    {// method cleans the stringholder in the circumstance that the user chooses to change the key in the midddle of the program.
    //use clearEleString method to accomplish that
               int index=0;
               while(index!=numberWords)
               {
                   clearEleString(stringsholder[index]);
                    index++;
               }
    }
        void clearEleString(char string [])
        {
               int index=0;
               while(string[index]!='\0')
               {
                    string[index]='\0';
                    index++;
               }
        }