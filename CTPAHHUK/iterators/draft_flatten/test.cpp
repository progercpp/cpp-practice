#include <iostream>

class X{
public:
    class Y{
    public:
        int c;
        Y() : c(a) {} // мы не видим переменную a
    };
    int a;
private:
    int b;
};