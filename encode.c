#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Strok.h"
#include "encode.h"
void printIndexes(int codes[][2]);
void resetcount();
int codes[5000][2];
int codesIndex=0;
char textToEncode[1500];
int instanceChaCount=-1;
int strWthChaCount=0;
//codes holds 2 index one for the word and one for the character index
// codesIndex keeps count of the number of character that are mapped by the two number
//both are externally declared in encode.h

void readTextForEncode()
{
    printf("ENTER A MESSAGE OF 1500 CHARACTERS TO ENCODE: \n");
    fgets(textToEncode, 1500, stdin);
    convertStringEleSmall(textToEncode);
    removeReturnChar(textToEncode);
   // printArray(textToEncode);
}

    void removeReturnChar(char textToEncode [])
    {
             int index=0;
             while(textToEncode[index]!='\0')
             {
                  if(textToEncode[index]==10)
                  {
                     // printf("Found the return char for removal\n");
                      textToEncode[index]='\0';
                  }
                  index++;
             }
    }
void encode()
{
     int index=0, randInstCha;
     while(textToEncode[index]!='\0')
     {
             if(textToEncode[index]!=' ')
             {
                randInstCha=random()%10;
               // printf("randInst %d:\n", randInstCha);
                addIndexsArray(textToEncode[index], randInstCha);
             }
             else{
                codes[codesIndex][0]=-2;
                codes[codesIndex][1]=-2;// double -2 represent space
              //  printf("%c\n", codes[codesIndex][0]);
                codesIndex++;
             }
             resetcount();
             index++;
     }
    // printIndexes(codes);
}
     void addIndexsArray(char letter, int randInstCha)
     {
             int indexStrWthCha[5000]={-1}, index=0, indexStrHld, answerIndex;
            // printf("In ther addIndexsArray method\n");
            // printf("letter is :%c\n", letter);
             collectWrdWthCha(indexStrWthCha, letter);
             if(indexStrWthCha[0]==-1)
             {
                codes[codesIndex][0]=-1;
                codes[codesIndex][1]=-1;// double -1 represent #
                //printf("%c %c\n",',', codes[codesIndex][0]);
                codesIndex++;
             }
             else
                while(index<strWthChaCount)
                {

                    indexStrHld=indexStrWthCha[index];
                   // printf("letter: %c, index word: %d\n", letter, indexStrHld);
                         index++;
                    answerIndex=findChaIndxString(stringsholder[indexStrHld], letter, randInstCha);
                    if(instanceChaCount==randInstCha)
                       {
                        codes[codesIndex][0]=indexStrHld;
                        codes[codesIndex][1]=answerIndex;
                        codesIndex++;
                        break;
                       }
                    if(instanceChaCount!=randInstCha && index==strWthChaCount)
                        index=0;
                }

     }
         void collectWrdWthCha(int indexStrWthCha[], char letter)
         {
                     int indexstrhld=0, indexcha=0;
                     //printf("In collectWrdWThCha method\n");
                     while(indexstrhld<wordcount)
                     {
                         if(strchr(stringsholder[indexstrhld], letter))
                            {
                              indexStrWthCha[indexcha]=indexstrhld;
                              indexcha++;
                              strWthChaCount++;
                            }
                        indexstrhld++;
                     }
         }
        int findChaIndxString(char string[], char letter, int randInstCha)
        {
             int index=0, answerindex=0;
             while(string[index]!='\0' && instanceChaCount!=randInstCha)
             {
                 if(letter==string[index])
                 {
                     instanceChaCount++;
                     answerindex=index;
                 }
                 index++;
             }
             return answerindex;
        }
        void resetcount()
        {
            instanceChaCount=-1;
            strWthChaCount=0;
        }
void printIndexes(int codes[][2])
{
      int index=0;
      while(index<codesIndex)
      {
          if(codes[index][0]>=0)
            printf("%d,%d", codes[index][0], codes[index][1]);
          else if(codes[index][0]==-1)
            printf("#");
          else
            printf(" ");
          if(index!=codesIndex-1 && (codes[index][1]!=-2 && codes[index+1][0]!=-2))
              printf(",");
               index++;
      }
}
void clear()
{
    int index=0;
    while(index<codesIndex)
    {
        codes[index][0]=0;
        codes[index][1]=0;
        index++;
    }
    codesIndex=0;
}
