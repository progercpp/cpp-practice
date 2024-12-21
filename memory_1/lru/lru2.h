#include <unordered_map>
#include <list>
#include <utility>
#include <iostream>

template <typename K, typename V>
class LruCache {
public:
    LruCache(std::size_t max_size) : max_size_(max_size) {}

    void Put(const K& key, const V& value) {
        // Если ключ уже существует, обновляем его значение и перемещаем его в конец
        if (data_map.find(key) != data_map.end()) {
            // Обновление существующего значения
            data_map[key]->second = value;
            // Перемещение (key, value) в конец списка
            usage_list.splice(usage_list.end(), usage_list, data_map[key]);
        } else {
            // Если кеш переполнен, удаляем наименее недавно использованный элемент
            if (usage_list.size() >= max_size_) {
                const K& lru_key = usage_list.front().first; 
                usage_list.pop_front();  // Удаляем LRU элемент
                data_map.erase(lru_key); // Удаляем его из мапы
            }
            // Добавляем новый элемент
            usage_list.emplace_back(key, value);
            data_map[key] = --usage_list.end(); // Сохраняем итератор на элемент в мапе
        }
    }

    bool Get(const K& key, V* value) {
        auto it = data_map.find(key);
        if (it == data_map.end()) {
            // Ключ не найден
            return false;
        }
        // Ключ найден, извлекаем значение и обновляем порядок использования
        *value = it->second->second; 
        // Перемещаем этот элемент в конец списка
        usage_list.splice(usage_list.end(), usage_list, it->second);
        return true;
    }

private:
    std::size_t max_size_;
    std::list<std::pair<K, V>> usage_list; // Список для хранения пар (ключ, значение)
    std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> data_map; // Хранит итераторы на элементы списка
};
