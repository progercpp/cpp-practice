#include <string>
#include <cassert>
#include "task.cpp"
#include <iostream>

void test(const char* lhs, const char* rhs) {
    std::cout << "lhs = " << lhs << "\trhs = " << rhs << "\n";
    // char* result = nullptr;
    char* result = concat(lhs, rhs);
    std::cout << "result = " << result << "\n"; std::cout.flush();
    assert(std::string_view(result) == std::string(lhs) + std::string(rhs));
    delete[] result;
    std::cout << "result = " << result << "\n"; std::cout.flush();
}

int main () {
    // test("lol ", "I am here!");
    // std::cout << "Ok\n"; std::cout.flush();
    // test("", "I am here!");
    // std::cout << "Ok\n"; std::cout.flush();
    test("Hi", "");
    std::cout << "Ok\n"; std::cout.flush();
    test("", "");
    std::cout << "Ok\n"; std::cout.flush();
    return 0;
}
