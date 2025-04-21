#include <iostream>
#include <queue>
#include <vector>
#include <utility> // для std::pair

// Кастомный компаратор для std::priority_queue
template<typename T>
struct CustomComparator {
    bool operator()(const std::pair<int, T>& a, const std::pair<int, T>& b) {
        // Для max-очереди (большие значения с наивысшим приоритетом)
        return a.first < b.first; // Сравнение по первому элементу пары
    }
};

template<typename T>
class MyClass {
public:
    void Put(T value) {
        t--;
        pq.push({t, value});
    }
    T Get() {
        t--;
        T value = pq.top().second;
        pq.push({t, value});
        return value;
    }
    void Pop() {
        pq.pop();
    }
    void Clear() {
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            std::cout << cur.second << "\n";
        }
    }

private:
    int t = 0;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, CustomComparator<T>> pq;
};

int main() {
    MyClass<std::string> mc;
    mc.Put("abacaba");
    mc.Put("b");
    mc.Put("c");
    mc.Get();
    // mc.Get();
    // mc.Pop();
    mc.Clear();
    // std::cout << mc.Get() << "\n";
    // mc.Pop();
    // std::cout << mc.Get() << "\n";

    return 0;
}
