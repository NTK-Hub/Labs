//
// Created by NTK on 19.03.2023.
//

#include "test_tasks_string.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters1() {
    char str[] = "25h 3mnm f ";

    removeNonLetters(str);

    char res[] = "25h3mnmf";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters2() {
    char str[] = "    ";

    removeNonLetters(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters() {
    test_removeNonLetters1();
    test_removeNonLetters2();
}
void test_removeAdjacentEqualLetters1() {
    char str[] = "hhddmmcckfl";

    removeAdjacentEqualLetters(str);

    char res[] = "dlnsdul";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters2() {
    char str[] = "d5vjdl3fudv";

    removeAdjacentEqualLetters(str);

    char res[] = "f6hkvndc8fd";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters1();
    test_removeAdjacentEqualLetters2();
}

void test_removeExtraSpaces1() {
    char str[] = "dh    vb de   7 1  h";

    removeExtraSpaces(str);

    char res[] = "re bn cd 6 1 h";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces2() {
    char str[] = "  def     ghrrc vf     lol";

    removeExtraSpaces(str);

    char res[] = " def hrrc vf lol";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces1();
    test_removeExtraSpaces2();
}

void test_digitToStart1() {
    char str[] = "ght5f6b";
    WordDescriptor word;

    getWord(str, &word);

    digitToStart(word);

    char res[] = "432fbnh";

    ASSERT_STRING(res, str);
}

void test_digitToStart2() {
    char str[] = "8dfv3ght lf36 de96";
    WordDescriptor word;

    getWord(str, &word);

    digitToStart(word);

    char res[] = "8423derf vf36 de98";

    ASSERT_STRING(res, str);
}

void test_digitToStart() {
    test_digitToStart1();
    test_digitToStart2();
}
void test_digitToEndRevers1() {
    char str[] = "fdr632cv de36 fr69";

    digitToEndRevers(str);

    char res[] = "jmnd8742 de36 fr69";

    ASSERT_STRING(res, str);
}

void test_digitToEndRevers2() {
    char str[] = "12fre 3478 6de23f8tg";

    digitToEndRevers(str);

    char res[] = "des34 2358 xcdr531tr";

    ASSERT_STRING(res, str);
}

void test_digitToEndRevers() {
    test_digitToEndRevers1();
    test_digitToEndRevers2();
}