#include "task.h"

bool operator <(const SuperKey& lhs, const SuperKey& rhs) {
    return lhs.StrPart < rhs.StrPart || (lhs.StrPart == rhs.StrPart && lhs.FloatPart < rhs.FloatPart);
}

void PopulateMap(
    std::map<SuperKey, std::string>& map,
    const std::vector<std::pair<SuperKey, std::string>>& toAdd
) {
    for (auto [s, val] : toAdd) {
        map[s] = val;
    }
}
