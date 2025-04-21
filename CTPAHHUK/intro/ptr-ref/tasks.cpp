#include "tasks.h"
#include <iostream>

template<class T>
T min(T a, T b) {
    if (a < b) return a;
    return b;
}

template<class T>
T max(T a, T b) {
    if (a > b) return a;
    return b;
}
void NPointers::Increment(int *x) {
    *x = *x + 1;
}
 
int NPointers::Multiply(int a, int b, bool* flag) {
    int res = a * b;
    *flag = !((res / a == b && res % a == 0) && (res / b == a && res % b == 0));
    return res;
}

int NPointers::ScalarProduct(const int* a, const int* b, int sz) {
    int res = 0;
    for (int i = 0; i < sz; ++i) {
        res += (*(a + i)) * (*(b + i));
    }
    return res;
}

int NPointers::SizeOfMaximumSquareOfCrosses(const char* a, int n, int m) {
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // a[i][j] -- левый верхний угол
            // std::cout << "i = " << i << "\tj = " << j << "\n";
            for (int k = 0; k < min(n - i, m - j); ++k) {
                bool flag = true;
                // std::cout << "k = " << k << "\t";
                for (int x = i; x <= i + k; ++x) {
                    for (int y = j; y <= j + k; ++y) {
                        if (*(a + x * m + y) != '+') flag = false;
                    }
                }
                // std::cout << "flag = " << flag << "\n\n";
                if (flag) mx = max(mx, k + 1);
            }
        }
    }
    return mx;
}

long long* NPointers::MultiplyToLongLong(int a, int b) {
    long long multiply = ((long long) a) * ((long long) b);
    long long* res = new long long (multiply);
    return res;
}

void NReferences::MultiplyInplace(int& a, int b) {
    a = a * b;
}

int NReferences::CompareArraysByAverage(const int* a, int n, int* b) {
    int sm_a = 0;
    int sm_b = 0;
    for (int i = 0; i < n; ++i) {
        sm_a += *(a + i);
    }
    int m = 5;
    for (int i = 0; i < m; ++i) {
        sm_b += *(b + i);
    }
    // std::cout << "n = " << n << "\tm = " << m <<"\tsm_a = " << sm_a << "\tsm_b = " << sm_b << "\n";
    if (sm_a * m < sm_b * n) {
        return -1;
    } else if (sm_a * m == sm_b  * n) {
        return 0;
    } else {
        return 1;
    }
}
