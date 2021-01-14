#ifndef STROK_H
#define STROK_H

extern char stringsholder[5000][15];
extern int  wordcount;
void  readEleStringsholder(FILE *infile, char stringsholder[][15]);
void convertStringEleSmall(char string[]);
void clearstringsholder(char stringsholder[][15], int numberWords);
void clearEleString(char string []);


#endif