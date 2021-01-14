/*
   Name Abenezer Gebeyehu
   CS 262
   lab section 218
*/
#include<stdio.h>
#include<stdlib.h>
#include "readFile.h"
#include "Strok.h"
#include "readfile2.h"
#include "encode.h"
#include "writeFile.h"
#include "decode.h"
int readsinNumber();
void promptsMenu();
void assignFunction(int number);
int isStringholderEmpty(char stringsholder[][15]);
//stringholder, a multi array that holds words from the key, is declared externally in Strok.h; also the word count.
// and used by the other files
//the filname double array that holds the file names for each instances is externally declared in readFile.h.
//logic starts in readFile.h with it c source file readfile.c ends at decode.h and its source file. Like how it is in the "include"
//everything comes together in project2_agebeyeh_218.c
int main()
{
   printf("WELCOME TO ENCODING AND DECODING MESSAGE PROGRAM\n");
   srand(1469);
   promptsMenu();
   return 0;
}
void promptsMenu()
{
   printf(" PLEASE CHOOSE FROM THIS OPTIONS\n");
   printf(" 1) READ A FILE NAME OF THE CIPHER KEY\n");
   printf(" 2) ENCODE A MESSAGE GIVEN USING A CIPHER KEY\n");
   printf(" 3) DECODE AN ENCODED MESSAGE USING A CIPHER KEY\n");
   printf(" 4) EXIT THE PROGRAM\n");
   assignFunction(readsinNumber());
}
int readsinNumber()
{
    char number[4];
    int  numberHolder;
    fgets(number, 4, stdin);
    sscanf(number, "%d", &numberHolder);
    return  numberHolder;
}
void assignFunction( int number)
{
    switch(number){
    case 1:
         if(!(isStringholderEmpty(stringsholder))){
            clearstringsholder(stringsholder, wordcount);
             wordcount=0;}
         inputFileName(filename);
         openreadFromFile(filename);
         promptsMenu();
        break;
    case 2:
         if(isStringholderEmpty(stringsholder))
         {
             inputFileName(filename);
             openreadFromFile(filename);
         }
         readTextForEncode();
         encode();
         inputFileNameCh2(filename);
         openWriteOnFile(filename);
         clear();
         promptsMenu();
        break;
    case 3:
           if(isStringholderEmpty(stringsholder))
         {
             inputFileName(filename);
             openreadFromFile(filename);
         }
        inputFileNameCh3(filename);
        openreadFromFileCh3(filename);
        decode();
        printDecodedMessage();
        clearString();
        promptsMenu();
        break;
    case 4:
         exit(0);
    default:
         printf("Error you have entered a choice that is not specified");
         printf("Please enter again");
         promptsMenu();}
}
int isStringholderEmpty(char stringsholder[][15])
{
         return (stringsholder[0][0]=='\0')? 1 : 0;

}
