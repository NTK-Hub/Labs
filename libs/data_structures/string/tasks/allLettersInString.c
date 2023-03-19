//
// Created by NTK on 19.03.2023.
//

#include "allLettersInString.h"

#define MAX_UNCHAR 128

bool allLettersInString(char *str, WordDescriptor w) {
    bool strSymbols[MAX_UNCHAR + 1] = {false};

    while (*str) {
        strSymbols[*str] = true;
        str++;
    }
    char *beginWord = w.begin;

    while (beginWord < w.end) {
        if (strSymbols[*beginWord] == false)
            return false;

        beginWord++;
    }

    return true;
}