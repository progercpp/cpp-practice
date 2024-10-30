#include "task.h"

char* concat(const char* lhs, const char* rhs) {
    // find lengths:
    int length_lhs = 0;
    for (length_lhs = 0; *(lhs + length_lhs) != '\0'; ++length_lhs);
    int length_rhs = 0;
    for (length_rhs = 0; *(rhs + length_rhs) != '\0'; ++length_rhs);

    // generate string
    int length_result = length_lhs + length_rhs;
    length_result++;
    char* result = new char[length_result];
    
    // fill string
    for (int i = 0; i < length_lhs; ++i) {
        result[i] = lhs[i];
    }
    for (int i = 0; i < length_rhs; ++i) {
        result[length_lhs + i] = rhs[i];
    }
    result[length_result - 1] = '\0';
    return result;
}
