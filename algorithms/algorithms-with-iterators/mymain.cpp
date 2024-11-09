#include "mytask.h"
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

void TestFibonacciRange() {
    FibonacciRange r(10);

    assert(std::is_sorted(r.begin(), r.end()));

    vector<uint64_t> fibonacciVec(r.begin(), r.end());
    assert(fibonacciVec == vector<uint64_t>({1, 2, 3, 5, 8, 13, 21, 34, 55, 89}));

    vector<uint64_t> doubledFibonacci(r.size());
    Transform(r.begin(), r.end(), doubledFibonacci.begin(), [](uint64_t fib){return fib * 2;});
    assert(doubledFibonacci == vector<uint64_t>({2, 4, 6, 10, 16, 26, 42, 68, 110, 178}));
}


int main () {
    std::cout << "start\tKEK\n"; std::cout.flush();

    TestFibonacciRange();

    std::cout << "assertion passed\n"; std::cout.flush();
    return 0;
}
