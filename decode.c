#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "readfile2.h"
#include "Strok.h"
#include "decode.h"
char string[5000];
int  indexAns=0;
void decode()
{
    int index=0;
    while(index<encodedtextwordcount)
    {
        decodeEncodedWord(encodedtext[index]);
        if(index<encodedtextwordcount-1)
            string[indexAns++]=' ';
     index++;

    }
    string[indexAns]='\0';
}
void decodeEncodedWord(char encodedWord[])
{
    int count=0, stringIndex, chaIndex;
    char *token, comma[1]=",";
    token=strtok(encodedWord, comma);
    while(token!=NULL)
    {
      if(strcmp(token, "#")!=0)
      {
        if(count==0)
        {
           stringIndex=atoi(token);
           checkStringIndexOutBound(stringIndex);
           count++;
        }
        else
        {
            chaIndex=atoi(token);
            checkChaIndexOutBound(chaIndex);
            count=0;
            string[indexAns]=mapStringIndexsCha(stringIndex, chaIndex);
            indexAns++;
        }
      }
       else
       {
          string[indexAns]='#';
          indexAns++;
       }
     token=strtok(NULL, comma);
    }
}
    char mapStringIndexsCha(int stringIndex, int chaIndex)
    {
        return stringsholder[stringIndex][chaIndex];
    }
    void checkChaIndexOutBound(int index)
    {
        if(index>15)
        {
           printf("The index for the character is out of bound\n");
           printf("exiting the program\n");
            exit(0);
        }
    }
    void checkStringIndexOutBound(int index)
    {
        if(index<0 || index>(wordcount-1))
            {
            printf("The String Index is out of bound\n");
            printf("Exiting the program\n");
            exit(0);
            }
    }
void printDecodedMessage()
{
     int stringlength=strlen(string), index=0;
     printf("THE DECODED MESSAGE:\n");
     while(index<stringlength)
     {
        printf("%c", string[index]);
        // if(string[index]=='.')
        //     printf("\n");
        index++;
     }
     printf("\n");
}
void clearString()
{
    int index=0;
    while(index<indexAns)
     {
      string[index]='\0';
      index++;
     }
     indexAns=0;
}
