add_library(data_structures
        bitset/bitset.c
        matrix/matrix.c
        vector/vector.c
        string/string_.c
        )
target_link_libraries(data_structures algorithms)
