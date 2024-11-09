#include <functional>
#include <iostream>
#include <vector>

template <typename T, typename P>
bool Any(const std::vector<T>& list, P predicate) {   
    return std::any_of(list.begin(), list.end(), predicate);
}

bool check(int number, std::function<bool(int)>predicate) {
    return predicate(number);
}

int main() {
    // std::cout << Any(std::vector<int>{32432}, [](int a) {return a % 2;}) << std::endl;
    int n = 10;
    while (n != 0) {
        std::cin >> n;
        if (check(n, [](int a) {return a % 2;})) {
            std::cout << "YES\n"; std::cout.flush();
        }  else {
            std::cout << "NO\n"; std::cout.flush();
        }
    }
}