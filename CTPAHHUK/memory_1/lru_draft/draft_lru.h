// #include <iostream>
#include <unordered_map>
#include <queue>
#include <deque>

template<typename K>
class Foo {
    Foo(int x, K y) : a(x), b(y) {}
    Foo() {}
public:
    // std::pair<int, K> p;
    int a;
    K b;
};

template<typename K>
class Compare {
public:
    bool operator() (Foo l, Foo r) {
        return l.a < r.a;
    }
};

template <typename K, typename V>
class LruCache {
public:
    LruCache(std::size_t max_size) : max_size_(max_size), t(0) {}
    
    void Put(const K& key, const V& value) {
        t--;
        pq.push({t, key});
        last_input[key] = t;
        um[key] = value;
        update();
    }

    bool Get(const K& key, V* value) {
        if (um.count(key) == 0) {
            value = nullptr;
            return false;
        }
        t--;
        pq.push({t, key});
        last_input[key] = t;
        value = &um[key];
        return true;
    }

    void update() {
        while (um.size() > max_size_) {
            std::pair<int, K> last = pq.top();
            if (last_input[last.second] == last.first) {
                um.erase(last.second);
                last_input.erase(last.second);
            }
            pq.pop();
        }
    }
private:
    std::unordered_map<K, V> um;
    std::unordered_map<K, int> last_input;     // последнее реальное вхождение
    std::size_t max_size_;
    int t;
    // auto lamda = [](std::pair<int, K> a, std::pair<int, K> b) {return a.first < b.first;};
    // std::priority_queue<std::pair<int, K>, std::vector<std::pair<int, K>>, [](std::pair<int, K> a, std::pair<int, K> b) {return a.first < b.first;}> pq; // <time, key>
    std::priority_queue<Foo, std::vector<Foo>, Compare> pq; // <time, key>
};

// std::priority_queue<std::pair<int, K>, std::vector<std::pair<int, K>>, [](std::pair<int, K> a, std::pair<int, K> b) {return a.first < b.first;}> pq;
