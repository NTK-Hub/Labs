//
// Created by NTK on 19.03.2023.
//

#include "printWordsRevers.h"

void printWord(WordDescriptor w) {
    char *endBuffer = copy(w.begin, w.end, _stringBuffer);

    *endBuffer = '\0';

    printf("%s", _stringBuffer);
}

void printWordsRevers(char *str) {
    BagOfWords w;
    getBagOfWords(&w, str);

    for (int i = w.size - 1; i >= 0; --i) {
        printWord(w.words[i]);
        printf("\n");
    }
}