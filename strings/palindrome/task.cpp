#include "task.h"
// #include <iostream>

bool isalpha_(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

char tolower_(char c) {
    if ('A' <= c && c <= 'Z') return c + 'a' - 'A';
    return c;
}

bool is_palindrome(const std::string& s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        // std::cout << "l = " << l << "\tr = " << r << "\n"; std::cout.flush();
        if (!isalpha_(s[l])) {
            l++;
            continue;
        }
        if (!isalpha_(s[r])) {
            r--;
            continue;
        }
        if (tolower_(s[l]) != tolower_(s[r])) return false;
        l++; r--;
    }
    return true;
}