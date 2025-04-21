#pragma once


namespace NPointers {
    void Increment(int *x);
    int Multiply(int a, int b, bool* flag);
    int ScalarProduct(const int* a, const int* b, int sz);
    int SizeOfMaximumSquareOfCrosses(const char* a, int n, int m);
    long long* MultiplyToLongLong(int a, int b);
}

namespace NReferences {
    void MultiplyInplace(int& a, int b);
    int CompareArraysByAverage(const int* a, int n, int* b);
}
