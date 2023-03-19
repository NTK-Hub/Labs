//
// Created by NTK on 12.03.2023.
//

#include "string_.h"
#include "stdbool.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0') {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

bool cmpWord(WordDescriptor w1, WordDescriptor w2) {
    char *start1 = w1.begin;
    char *start2 = w2.begin;
    unsigned long size = w1.end - start1;
    if (size != w2.end - start2)
        return false;

    return memcmp(start1, start2, size) == 0;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    memcpy(beginDestination, beginSource,
           sizeof(char) * (endSource - beginSource));

    return beginDestination + (endSource - beginSource);
}

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
    while (endSource > beginSource) {
        if (f(*beginSource))
            *beginDestination++ = *beginSource;

        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource))
            *beginDestination++ = *rbeginSource;
        rbeginSource--;
    }

    return beginDestination;
}

char *getEndOfString(char *str) {
    while (*str)
        str++;

    return str;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;

}

int getWordRevers(char *rbegin, char *rend, WordDescriptor *word) {
    char *word_end = findNonSpaceReverse(rbegin, rend);

    if (word_end == rend)
        return 0;

    char *word_begin = findSpaceReverse(word_end, rend);

    word->begin = word_begin + 1;
    word->end = word_end + 1;

    return 1;

}

char *findComma(char *begin) {
    while (*begin != '\0') {
        if (*begin == ',')
            return begin;

        begin++;
    }

    return begin;
}

int getWordSeparatedByComma(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findComma(word->begin);

    return 1;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    if (w1.end - w1.begin != w2.end - w2.begin)
        return 0;

    return !memcmp(w1.begin, w2.begin, w1.end - w1.begin);
}

void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;
    WordDescriptor w;

    while (getWord(s, &w)) {
        bag->words[bag->size++] = w;
        s = w.end;
    }
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    destination = copy(word.begin, word.end, destination);
    *destination = '\0';
}
