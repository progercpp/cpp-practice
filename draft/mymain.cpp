// #include <iostream>
// #include <cassert>

// #include "task.cpp"

// void test() {
//     assert(normalize("/../../foo/././bar/../bar/./baz//1.txt") == "/foo/bar/baz/1.txt");
//     assert(normalize("../../foo/././bar/../bar/./baz//1.txt") == "../../foo/bar/baz/1.txt");
//     assert(normalize("..") == "..");
//     assert(normalize(".") == ".");
//     assert(normalize("/.") == "/");
//     assert(normalize("/..") == "/");
//     assert(normalize("/../.") == "/");
//     assert(normalize("../.") == "..");
//     assert(normalize("file.txt") == "file.txt");
//     assert(normalize("file.txt/./rfd/./") == "file.txt/rfd");
// }

// int main() {
//     test();
//     std::cout << normalize(("file.txt/./rfd/.///va/")) << "\n";
//     std::cout << "OK\n"; std::cout.flush();
//     std::cout << normalize(("/../../foo/././bar/../bar/./baz//1.txt")) << "\n";

//     string s = "/a1/b2/c3";
//     exit_from_catalog(s);
//     go_to_catalog(s, "byaka");
//     string command = "..";
//     update(s, command);
//     command = "egamesports";
//     update(s, command);
//     cout << s << "\n";
// }