add_library(str string/string_.h string/string_.c
        # string/tasks/digitToStartTransform.h
        # string/tasks/reverseWords.h
        # string/tasks/replaceDigitsBySpaces.h
        # ...
        # < файл с решением задачи для следующей лабораторной >
        # ...
        # string/tasks/hasPairOfWordsWithEqualLetterSet.h
        # string/tasks/printWordsNonEqualLastWord.h
        )
# описываем, что для запуска project потребуется сборка str
target_link_libraries(project str)
