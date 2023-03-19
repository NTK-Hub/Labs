//
// Created by NTK on 19.03.2023.
//

#include "wordsOrdered.h"

bool wordOrdered(char *str) {
    WordDescriptor w1;
    WordDescriptor w2;

    if (!getWord(str, &w1))
        return true;

    while (getWord(str, &w2)) {
        if (!areWordsEqual(w1, w2) && strcmp(w1.begin, w2.begin) > 0)
            return false;

        w1 = w2;
        str = w2.end;
    }

    return true;
}