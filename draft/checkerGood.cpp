#include "array.h"
// #include "arrayExp.h"
// #include "arrayGood.h"
#include <cassert>
#include <sstream>
#include <array>

void CheckOutputOperator() {
    std::stringstream out;
    std::string ans;
    Array a = Array(5, out, 5);

    getline(out, ans);
    assert(ans == "Constructed with default. Result Array's capacity is 10 and size is 5, elements are: 5, 5, 5, 5, 5");
    
    out << a << "\n";
    getline(out, ans);

    // debug
    // std::string result = ans;
    // std::cout << "debug ---\n";
    // std::cout << "a = " << a << "\n";
    // std::cout << "result = " << result << "$\n";
    // std::cout << "--- end debug\n";
    
    assert(ans == "Result Array's capacity is 10 and size is 5, elements are: 5, 5, 5, 5, 5");
}


void CheckDefaultConstructor() {
    std::stringstream out;  
    std::string ans;

    {
        Array array = Array(out);
        getline(out, ans);
        assert(ans == "Constructed. Result Array's capacity is 2 and size is 0");
        getline(out, ans);
        // array.RewriteOstream();
        std::cout << "ans = " << ans << "\n";
        std::cout << "delete\n";
    }
    getline(out, ans);
    std::cout << "ans = " << ans << "\n";
    assert(ans == "Destructed 0");
}

void CheckRewriteOstream() {
    std::stringstream out;
    Array arr(5, out, 1);
    std::string res = "";
    std::getline(out, res);
    std::cout << res << "\n";
    arr.RewriteOstream();
    std::cout << res << "\n";
}

int main() {
    // CheckOutputOperator();
    // CheckDefaultConstructor();
    CheckRewriteOstream();
}
