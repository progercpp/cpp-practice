#include <string>

/*
 * Постановка задачи:
 * Написать функцию, которой на вход подается строка из ascii-символов;
 * функция возвращает true, если строка является палиндромом, и false, если не является.
 * При этом не нужно в проверке учитывать символы, не являющиеся буквами, а также не нужно учитывать регистр букв.
 * Пустая строка считается палиндромом.
 * Пример палиндрома: "Do geese see God?"
 */


bool isalpha_(char c);

char tolower_(char c);

bool is_palindrome(const std::string& s);


