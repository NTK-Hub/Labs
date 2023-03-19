//
// Created by NTK on 19.03.2023.
//

#include "replaceNumberWithSpaces.h"

void replaceNumberWithSpaces(char *str) {
    char *endBuffer = copy(str, str + strlen_(str), _stringBuffer);
    char *beginBuffer = _stringBuffer;
    while (beginBuffer < endBuffer) {
        if (isdigit(*beginBuffer)) {
            int nSpaces = *beginBuffer - '0';
            for (int i = 0; i < nSpaces; ++i)
                *str++ = ' ';

        } else
            *str++ = *beginBuffer;

        beginBuffer++;
    }

    *str = '\0';
}