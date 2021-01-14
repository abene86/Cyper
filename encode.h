#ifndef ENCODE_H
#define ENCODE_H

  void readTextForEncode();
     void printArray(char readTextForEncode[]);
     void removeReturnChar(char textToEncode []);
  void encode();
      void addIndexsArray(char letter, int randInstCha);
      void collectWrdWthCha(int indexStrWthCha[], char letter);
       int findChaIndxString(char string[], char letter, int randInstCha);
  void clear();
  extern int codes[5000][2];
  extern int codesIndex;

#endif