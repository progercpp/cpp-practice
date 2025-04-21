#include <iostream>
#include <memory>

class Root {
public:
    Root(char c, int cnt) {
        data_ = "";
        for (int i = 0; i < cnt; ++i) {
            data_.push_back(c);
        }
    }
protected:
    int id = 0;
private:
    std::string data_;
};

class Root_2 final {
public:
    Root_2(std::string str) : str_(str) {}
protected:
    int id = 0;
private:
    std::string str_;
};

// class Child_2 : public Root_2 {

// }

class Child : protected Root {
public:
    Child(int age, char c, int cnt) : Root(c, cnt), age_(age) {}
    void Print() const {
        std::cout << "id = " << id << "\n";
    }
private:
    int age_;
};

int main() {
    enum class Type {
        MoveCursorLeft = 0,
        MoveCursorRight,
        MoveCursorUp,
        MoveCursorDown,
        SelectText,
        InsertText,
        DeleteText,
        CopyText,
        PasteText,
        UppercaseText,
        LowercaseText,
        MoveToEnd,
        MoveToStart,
        DeleteWord,
        Macro,
    };

    return 0;
}
