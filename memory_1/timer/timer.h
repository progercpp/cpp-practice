#include <chrono>
#include <iostream>

class Timer {
public:
    Timer(std::chrono::milliseconds difference) {
        start = std::chrono::steady_clock::now();
        diff = difference;
    }
    bool Expired() const {
        auto cur_time = std::chrono::steady_clock::now();
        return cur_time - start > diff;
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    std::chrono::milliseconds diff;
};

class TimeMeasurer {
public:
    TimeMeasurer(std::ostream& out_) : out(out_) {
        out.clear();
        start = std::chrono::steady_clock::now();
    }
    ~TimeMeasurer() {
        auto cur_time = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - start).count();
        out << "Elapsed time: " << diff;
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::ostream& out;
};
