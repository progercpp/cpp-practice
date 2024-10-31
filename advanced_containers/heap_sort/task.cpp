#include "task.h"

std::vector<int> HeapSort(const std::vector<int>& v) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int x : v) {
        pq.push(x);
    }
    std::vector<int> res = {};
    while (!pq.empty()) {
        res.push_back(pq.top()); pq.pop();
    }
    return res;
}