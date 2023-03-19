//
// Created by NTK on 19.03.2023.
//

#include <memory.h>
#include "removeAdjacentEqualLetters.h"

void removeAdjacentEqualLetters(char *s) {
    if (*s == '\0')
        return;

    char *lastWriten = s;
    s++;

    while (*s) {
        if (*lastWriten != *s) {
            lastWriten++;
            memcpy(lastWriten, s, sizeof(char));
        }
        s++;
    }
    lastWriten++;
    *lastWriten = '\0';
}