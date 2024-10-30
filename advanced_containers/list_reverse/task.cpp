#include "task.h"

void ReverseList(std::list<int>& l) {
    std::list<int> res;
    for (int x : l) {
        res.push_front(x);
    }
    l = res;
}
