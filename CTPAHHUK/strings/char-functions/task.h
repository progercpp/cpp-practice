/*
 * Реализовать фукнцию isalpha, которая проверяет, является ли переданный символ буквой (конкретно латинской буквой)
 * Реализовать функцию tolower, которая превращает заглавные латинские буквы в маленькие, а другие символы возвращает неизменными
 */

// #include <iostream>
// bool isalpha(unsigned char c);
// unsigned char tolower(unsigned char c);

bool isalpha(unsigned char c) {
    // std::cout << (char) c << " = "<< int(c) << "\n";
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

char tolower(unsigned char c) {
    if ('A' <= c && c <= 'Z') return c + 'a' - 'A';
    return c;
}
