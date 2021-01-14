#ifndef READFILE2_H
#define READFILE2_H


void inputFileNameCh3(char filename[][50]);
void readDecodedFil(FILE *infile, char encodedtext[][75]);
void openreadFromFileCh3(char filename[][50]);
void printArray(char array[]);
extern char encodedtext[5000][75];
extern int encodedtextwordcount;
void printEncodedWords(char encodedtext[][75]);


#endif