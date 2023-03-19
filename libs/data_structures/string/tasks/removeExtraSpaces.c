//
// Created by NTK on 19.03.2023.
//

#include <memory.h>
#include "removeExtraSpaces.h"

void removeExtraSpaces(char *s) {
    if (*s == '\0')
        return;

    char *lastWriten = s;
    s++;

    while (*s) {
        if (isspace(*lastWriten) && isspace(*s)) {
            *lastWriten = ' ';
        } else {
            lastWriten++;
            memcpy(lastWriten, s, sizeof(char));
        }
        s++;
    }
    lastWriten++;
    *lastWriten = '\0';
}