#include <iostream>

class my_class {
public:
    void Get(int* value) {
        *value = data_;
    }
private:
    int data_ = 10;
};

int main() {
    my_class mc;
    int value = -5;
    mc.Get(&value);
    std::cout << "value = " << value << "\n";
    return 0;
}
