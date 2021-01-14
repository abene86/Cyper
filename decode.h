#ifndef DECODE_H
#define DECODE_H

void printDecodedMessage();
void decode();
    char mapStringIndexsCha(int stringIndex, int charindex);
    void decodeEncodedWord(char encodedWord[]);
    void checkChaIndexOutBound(int index);
    void checkStringIndexOutBound(int index);
void clearString();

#endif