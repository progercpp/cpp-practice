#include "tasks.h"

#include <iostream>

int NPointers::Increment(int *pointer) {
    return ++*pointer;
}
int MyNamespace::Sum(int a, int b) {
    return a + b;
}