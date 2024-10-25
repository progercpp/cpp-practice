#pragma once

long long abs_(long long x) {
    if (x >= 0) return x;
    else return -x;
}

class Range {
public:
    Range(long long n) : start_(0), end_(n), step_(1) {}
    Range(long long start, long long end) : start_(start), end_(end), step_(1) {}
    Range(long long start, long long end, long long step) : start_(start), end_(end), step_(step) {}

    class RandomAccessIterator {
    public:
        // using iterator_category = std::random_access_iterator_tag;
        using value_type = long long;
        using pointer = long long*;
        // using difference_type = ptrdiff_t;
        using reference = long long&;

        RandomAccessIterator(long long start_, long long step_) : CurValue(start_), Step(step_) {}
        // Коснтруктор для end();
        RandomAccessIterator(long long start_, long long end_, long long step_) {
            if (step_ > 0) {
                Step = step_;
                CurValue = start_;
                while (CurValue < end_) {
                    CurValue += step_;
                }
            } else {
                Step = step_;
                CurValue = start_;
                while (CurValue > end_) {
                    CurValue += step_;
                }
            }
        }
        // операторы доступа
        long long operator*() const {
            return CurValue;
        }

        // арифметические действия
        RandomAccessIterator& operator++() {
            CurValue += Step;
            return *this;
        }
        RandomAccessIterator operator++(int) {
            RandomAccessIterator copy_cur = *this;
            CurValue += Step;
            return copy_cur;
        }

        // операторы сравнения
        bool operator==(const RandomAccessIterator& other) const {
            return CurValue == other.CurValue && Step == other.Step;
        }
        bool operator!=(const RandomAccessIterator& other) const {
            return !(CurValue == other.CurValue && Step == other.Step);
        }
        bool operator<(const RandomAccessIterator& other) const {
            return CurValue < other.CurValue;
        }
        
    private:
        long long CurValue;
        long long Step;
        // long long End;
    };

    RandomAccessIterator begin() const {
        return RandomAccessIterator(start_, step_);
    }
    RandomAccessIterator end() const {
        return RandomAccessIterator(start_, end_, step_);
    }
    long long Size() const {
        return (abs_(end_ - start_) + abs_(step_) - 1) / abs_(step_);
    }
private:
    long long start_;
    long long end_;
    long long step_;
};
