// #include <iostream>
// #include <vector>
// #include <string>
// #include <memory>
// #include "task.h"
// #include <cassert>

// void TestDuplication() {
//     const auto first = std::make_shared<std::string>("first");
//     const auto second = std::make_shared<std::string>("second");
//     const auto third = std::make_shared<std::string>("third");

//     const std::vector<std::shared_ptr<std::string>> dedup {first, second, third, third, first, second};
//     const auto dup = Duplicate(dedup);

//     assert(*dup[0] == "first");
//     assert(*dup[1] == "second");
//     assert(*dup[2] == "third");
//     assert(*dup[3] == "third");
//     assert(*dup[4] == "first");
//     assert(*dup[5] == "second");

//     assert(dup[0] != dup[4]);
//     assert(dup[1] != dup[5]);
//     assert(dup[2] != dup[3]);

//     assert(dup[0].get() != first.get());
//     assert(dup[1].get() != second.get());
//     assert(dup[2].get() != third.get());
// }

// int main() {
//     TestDuplication();
//     std::cout << "Done\n";
//     const auto first = std::make_shared<std::string>("first");
//     const auto second = std::make_shared<std::string>("second");
//     const auto third = std::make_shared<std::string>("third");

//     const std::vector<std::shared_ptr<std::string>> dedup {first, second, third, third, first, second};
//     print(dedup);
//     return 0;
// }