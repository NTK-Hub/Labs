add_library(data_structures
        bitset/bitset.c
        matrix/matrix.c
        vector/vector.c
        string_/string_.c
        )
add_subdirectory(string_)
target_link_libraries(data_structures algorithms)