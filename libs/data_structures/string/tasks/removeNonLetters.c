//
// Created by NTK on 19.03.2023.
//

#include "removeNonLetters.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}