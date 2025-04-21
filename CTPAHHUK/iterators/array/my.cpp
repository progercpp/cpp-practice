#include "array.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 10;
const ll LINF = 1e15;
const ld LDINF = 1e8+10;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    // std::stringstream output;
    ostream out(nullptr);
    Array<int> arr(out);
    
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(7);
    arr.PushBack(-47);

    for (int i = 0; i < arr.Size(); ++i) {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
    cout << "\n";
    arr.PopBack();
    arr.PopBack();
    arr.PushBack(150);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
