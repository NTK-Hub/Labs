//
// Created by NTK on 19.03.2023.
//

#include "test_string_.h"

void test_find1() {
    char str[] = "dfgdfbv151d56";
    int lenghtStr = 7;
    char *res = str + lenghtStr;

    assert(find(str, str + lenghtStr, 'k') == res);
}

void test_find2() {
    char str[] = "dfj23r9s37wmv5";
    int lenghtStr = 14;
    char *res = &str[3];

    assert(find(str, str + lenghtStr, 'u') == res);
}

void test_find() {
    test_find1();
    test_find2();
}

void test_findNonSpace1() {
    char str[] = "  s6gv23r";
    char *res = &str[2];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace2() {
    char str[] = "   ";
    char *res = &str[3];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace() {
    test_findNonSpace1();
    test_findNonSpace2();
}


void test_findSpace1() {
    char str[] = "kli624f";
    char *res = &str[7];

    assert(findSpace(str) == res);
}

void test_findSpace2() {
    char str[] = "erg j32 1n";
    char *res = &str[3];

    assert(findSpace(str) == res);
}

void test_findSpace() {
    test_findSpace1();
    test_findSpace2();
}

void test_findSpaceReverse1() {
    char str[] = "lcd 3s l";
    char *res = &str[6];
    int lenghtStr = 8;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse2() {
    char str[] = "ervm364d";
    char *res = str;
    int lenghtStr = 8;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse() {
    test_findSpaceReverse1();
    test_findSpaceReverse2();
}

void test_findNonSpaceReverse1() {
    char str[] = "  \t  f";
    char *res = &str[5];
    int lenghtStr = 6;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse2() {
    char str[] = "   ";
    char *res = str;
    int lenghtStr = 3;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse1();
    test_findNonSpaceReverse2();
}

void test_strcmp1() {
    char str[] = "rlvmdtk 24";
    char res[] = "rlvmdtk 24";

    assert(!strcmp(str, res));
}

void test_strcmp2() {
    char str[] = "lcan 36";
    char res[] = "lcamelt 36";

    assert(strcmp(str, res));
}

void test_strcmp() {
    test_strcmp1();
    test_strcmp2();
}

void test_copy1() {
    char str[] = "elc4687";
    int lenghtStr = 7;

    char endStr[] = "b89";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copy(&str[2], &str[5], resBegin);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copy2() {
    char str[] = "elc4687";
    int lenghtStr = 7;

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copy(str, str + lenghtStr, resBegin);
    *resEnd = '\0';

    assert(!strcmp(str, resBegin));

    free(resBegin);
}

void test_copy() {
    test_copy1();
    test_copy2();
}

int isDigit(int x) {
    return x >= '0' && x <= '9';
}

int isNotDigit(int x) {
    return !isDigit(x);
}

void test_copyIf1() {
    char str[] = "h63r 1dlmct m";
    int lenghtStr = 13;

    char endStr[] = "3690";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIf(str, str + lenghtStr, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIf2() {
    char str[] = "h63r 1dlmct m";
    int lenghtStr = 13;

    char endStr[] = "db xwdq n";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIf(str, str + lenghtStr, resBegin, isNotDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIf() {
    test_copyIf1();
    test_copyIf2();
}

void test_copyIfReverse1() {
    char str[] = "ln7 3 6v8eln";
    int lenghtStr = 12;

    char endStr[] = "7413";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr, str - 1, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse2() {
    char str[] = "ln7 3 6v8eln";
    int lenghtStr = 11;

    char endStr[] = "lmd  m";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr, str, resBegin, isNotDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse() {
    test_copyIfReverse1();
    test_copyIfReverse2();
}

void test_getEndOfString1() {
    char str[] = "ln7 3 6v8eln";
    int lenghtStr = 12;

    char *res = str + lenghtStr;

    assert(getEndOfString(str) == res);
}

void test_getEndOfString2() {
    char str[] = "";

    char *res = str;

    assert(getEndOfString(str) == res);
}

void test_getEndOfString() {
    test_getEndOfString1();
    test_getEndOfString2();
}

void test_str() {
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();

    test_strcmp();

    test_copy();
    test_copyIf();
    test_copyIfReverse();

    test_getEndOfString();

}