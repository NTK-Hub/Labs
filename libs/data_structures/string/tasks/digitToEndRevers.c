//
// Created by NTK on 19.03.2023.
//

#include "digitToEndRevers.h"

void digitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);

    copyIfReverse(endStringBuffer - 1,
                  _stringBuffer - 1,
                  recPosition, isdigit);
}

void digitToEndRevers(char *str) {
    char *beginStr = str;
    WordDescriptor word;

    while (getWord(beginStr, &word)) {
        digitToEnd(word);
        beginStr = word.end;
    }
}