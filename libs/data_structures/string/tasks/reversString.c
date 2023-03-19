//
// Created by NTK on 19.03.2023.
//

#include "../string_.h"

void reversString(char *str) {
    if (*str == '\0')
        return;

    char *endBuffer = copy(str, getEndOfString(str), _stringBuffer);

    WordDescriptor w;

    while (getWordRevers(endBuffer - 1, _stringBuffer - 1, &w)) {
        str = copy(w.begin, w.end, str);
        *str++ = ' ';

        endBuffer = w.begin;
    }

    *(str - 1) = '\0';
}