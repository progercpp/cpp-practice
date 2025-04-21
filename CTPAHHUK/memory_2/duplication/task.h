#include <iostream>
#include <vector>
#include <memory>
#include <set>

std::shared_ptr<std::string> find_in_shared_vector(std::string& value, std::vector<std::shared_ptr<std::string>>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (*vec[i] == value) {
            return vec[i];
        }
    }
    return vec[0];
}

std::vector<std::shared_ptr<std::string>> DeDuplicate(const std::vector<std::unique_ptr<std::string>>& in) {
    std::vector<std::shared_ptr<std::string>> out;
    std::set<std::shared_ptr<std::string>> st;
    std::set<std::string> values;
    for (size_t i = 0; i < in.size(); ++i) {
        if (values.count(*in[i])) {
            out.push_back(find_in_shared_vector(*in[i], out));
        } else {
            values.insert(*in[i]);
            out.push_back(std::make_shared<std::string>(*in[i]));
        }
    }
    return out;
}

std::vector<std::unique_ptr<std::string>> Duplicate(const std::vector<std::shared_ptr<std::string>>& in) {
    std::vector<std::unique_ptr<std::string>> out;
    for (size_t i = 0; i < in.size(); ++i) {
        // std::cout << "in[" << i << "] = " << in[i] << "\n";
        out.push_back(std::make_unique<std::string>(*in[i]));
    }
    return out;
}

void print(const std::vector<std::shared_ptr<std::string>>& in) {
    std::vector<std::unique_ptr<std::string>> out;
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << "in[" << i << "] = " << *in[i] << "\n";
        out.push_back(std::make_unique<std::string>(*in[i]));
    }
}

void print(const std::vector<std::unique_ptr<std::string>>& in) {
    std::vector<std::unique_ptr<std::string>> out;
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << "in[" << i << "] = " << *in[i] << "\n";
        out.push_back(std::make_unique<std::string>(*in[i]));
    }
}

