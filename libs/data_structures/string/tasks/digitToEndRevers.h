//
// Created by NTK on 19.03.2023.
//

#ifndef LABS_DIGITTOENDREVERS_H
#define LABS_DIGITTOENDREVERS_H

#include "../../string/string_.h"

//перенести цифры в конец слова
void digitToEnd(WordDescriptor word);

//Преобразовать строку таким образом, чтобы цифры каждого слова были
//перенесены в конец слова, и изменить порядок следования цифр в слове
//на обратный, буквы перенести в начало слова
void digitToEndRevers(char *str);

#endif //LABS_DIGITTOENDREVERS_H
