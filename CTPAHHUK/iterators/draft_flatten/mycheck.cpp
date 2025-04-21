#include "flatten.h"

#include <iostream>
#include <vector>

struct TestData
{
    std::string name = "Boba";
    int age = 10;

    friend std::ostream& operator<<(std::ostream& os, const TestData& data_) {
        os << "name = " << data_.name << " \tage = " << data_.age;
        return os;
    }
};


int main() {
    std::vector<std::vector<int>> v = {{1, 2, 3, 4, 5}, 
                                        {6, 7, 8},
                                        {},
                                        {9, 10, 11, 12, 13, 14, 15, 16},
                                        {17, 18, 19, 20}};
    FlattenedVector fv(v);
    std::cout << fv << "\n";

    // for (int i = 0; i < 20; ++i) {
    //     // std::cout << fv[i];
    // }
    // for (auto x : v) {
    //     std::cout << x << " ";
    // }
    std::cout << "-------\n";
    // for (auto it = fv.begin(); it != fv.end(); ++it) {
    //     std::cout << *it << "\n";
    // }
    for (int x : fv) {
        std::cout << x << std::endl;
    }
    for (auto iter = fv.begin(); iter < fv.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
    std::cout << "------------\n";

    std::vector<std::vector<TestData>> vec = {{{"Petya", 13}, {"Boob", 1290}}, {}, {{"Ivan", 213}}};
    FlattenedVector<TestData> Flat(vec);

    for (auto x : Flat) {
        std::cout << x << std::endl;
    }
    std::cout << "------------\n";
    std::vector<std::vector<int>> vi = {{1, 2, 4, 5, 1}, }
    return 0;
}
