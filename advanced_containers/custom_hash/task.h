#include <unordered_map>
#include <vector>
#include <string>

struct SuperKey {
    std::string StrPart;
    int IntPart;
    float FloatPart;

    bool operator==(const SuperKey& rhs) const {
        return this->StrPart == rhs.StrPart && this->IntPart == rhs.IntPart && this->FloatPart == rhs.FloatPart;
    }
};

template<>
struct std::hash<SuperKey> {
    const int MOD = 1e9;
    size_t operator() (const SuperKey& sk) const {
        size_t hash_int = (sk.IntPart + MOD) % MOD;
        size_t hash_float = (sk.FloatPart);
        size_t hash_string = 0;
        for (char c : sk.StrPart) {
            hash_string *= 255;
            hash_string += c;
            hash_string %= MOD;
        }
        return (hash_int + hash_float + hash_string) % MOD;
    }
};

/*
 * Напишите хэш-функцию, реализовав специализацию шаблона std::hash для типа SuperKey
 * Напишите функцию PopulateHashMap, которая добавляет в hashMap пары ключ-значение из данного вектора toAdd
 */
void PopulateHashMap(
    std::unordered_map<SuperKey, std::string>& hashMap,
    const std::vector<std::pair<SuperKey, std::string>>& toAdd
);