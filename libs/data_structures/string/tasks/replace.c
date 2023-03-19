//
// Created by NTK on 19.03.2023.
//

#include "replace.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr = source;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        char *endBuff = copy(source, getEndOfString(source) + 1, _stringBuffer);
        endBuff = '\0';
        readPtr = _stringBuffer;
    }

    WordDescriptor word;

    while (getWord(readPtr, &word)) {
        if (cmpWord(word, word1))
            recPtr = copy(word2.begin, word2.end, readPtr);
        else
            recPtr = copy(word.begin, word.end, recPtr);

        *recPtr = ' ';
        recPtr++;
        readPtr = word.end;
    }

    if (recPtr != source)
        *--recPtr = '\0';
}