#include <iostream>
#include <unordered_map>
#include <queue>

template<typename T>
struct CustomComparator {
    bool operator()(const std::pair<int, T>& a, const std::pair<int, T>& b) {
        return a.first > b.first;
    }
};

template <typename K, typename V>
class LruCache {
public:
    LruCache(std::size_t max_size) : max_size_(max_size), t(0) {}
    
    void Put(const K& key, const V& value) {
        t++;
        pq.emplace(t, key);
        last_input[key] = t;
        um[key] = value;
        if (max_size_ < 100 && um.size() == max_size_ + 1) update();
    }

    bool Get(const K& key, V* value) {
        if (um.count(key) == 0) {
            value = nullptr;
            return false;
        }
        t++;
        pq.emplace(t, key);
        last_input[key] = t;
        *value = um[key];
        // clear_pq();
        return true;
    }
    
    void inline clear_pq() {
        // удаляем старую версию
        std::pair<int, K> last = pq.top();
        if (last_input[last.second] != last.first) {
            pq.pop();
        }
        // while (true) {
        //     std::pair<int, K> last = pq.top();
        //     if (last_input[last.second] != last.first) {
        //         pq.pop();
        //     } else {
        //         break;
        //     }
        //     break;
        // }
    }
    void inline update() {
        while (um.size() == max_size_ + 1) {
            std::pair<int, K> last = pq.top();
            if (last_input[last.second] == last.first) {
                um.erase(last.second);
                last_input.erase(last.second);
            }
            pq.pop();
            // break;
        }
    }
    void print() {
        std::cout << "----- cache -----\n";
        auto pq_prev = pq;
        while (!pq_prev.empty()) {
            std::pair<int, K> cur = pq_prev.top();
            pq_prev.pop();
            std::cout << "cur = " << cur.first << "\t\t" << cur.second << "\n";
        }
        std::cout << "-----------------\n";
        std::cout.flush();
    }
private:
    std::unordered_map<K, V> um;
    std::unordered_map<K, int> last_input;     // последнее реальное вхождение
    std::size_t max_size_;
    std::priority_queue<std::pair<int, K>, std::vector<std::pair<int, K>>, CustomComparator<K>> pq;
    int t;
};
