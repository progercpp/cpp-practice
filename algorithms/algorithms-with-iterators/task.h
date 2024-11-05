#include <cstdlib>
#include <iterator>
#include <iostream>
#include <cstdint>

template<class InputIt, class OutputIt, class UnaryOperation>
void Transform(InputIt firstIn, InputIt lastIn, OutputIt firstOut, UnaryOperation op) {
    auto res = firstOut;
    for (auto iter = firstIn; iter < lastIn; ++iter, ++res) {
        *res = op(*iter);
    }
}


template<class BidirIt, class UnaryPredicate>
void Partition(BidirIt first, BidirIt last, UnaryPredicate p) {
    for (auto iter1 = first; iter1 < last; ++iter1) {
        for (auto iter2 = (iter1 + 1); iter2 < last; ++iter2) {
            if (!p(*iter1) && p(*iter2)) {
                auto value1 = *iter1;
                auto value2 = *iter2;
                *iter1 = value2;
                *iter2 = value1;
            }
        }
    }

}

// add(куда, что)
template<class InputIt1, class InputIt2>
void add(InputIt1& where, InputIt2& what) {
    *where = *what;
    where++;
    what++;
}

template<class InputIt1, class InputIt2, class OutputIt>
void Merge(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt firstOut) {
    auto iter1 = first1;
    auto iter2 = first2;
    auto iter = firstOut;
    while (!(iter1 == last1 && iter2 == last2)) {
        if (iter1 == last1){
            add(iter, iter2);
        } else if (iter2 == last2) {
            add(iter, iter1);
        } else if (*iter1 <= *iter2) {
            add(iter, iter1);
        } else {
            add(iter, iter2);
        }
    }
}

class FibonacciRange {
public:

    class Iterator {
        friend class FibonacciRange;
    public:
        using value_type = uint64_t;
        using difference_type = ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::input_iterator_tag;

        Iterator(uint64_t* ptr) : ptr_(ptr) {}

        value_type operator *() const {
            return *ptr_;
            // разыменование итератора -- доступ к значению
        }

        Iterator& operator ++() {
            // prefix increment
            ++ptr_;
            return *this;
        }

        Iterator operator ++(int) {
            // postfix increment
            auto copy = *this;
            ++ptr_;
            return copy;
        }

        bool operator ==(const Iterator& rhs) const {
            return this->ptr_ == rhs.ptr_;
        }
        bool operator !=(const Iterator& rhs) const {
            return this->ptr_ != rhs.ptr_;
        }

        bool operator <(const Iterator& rhs) const {
            return this->ptr_ < rhs.ptr_;
        }
    private:
        uint64_t* ptr_ = nullptr;
    };

    FibonacciRange(size_t amount) : n(amount) {
        data_ = new uint64_t[n + 1];
        data_[0] = 1;
        data_[1] = 1;
        for (size_t i = 2; i <= n; ++i) {
            data_[i] = data_[i - 1] + data_[i - 2];
        }
    }

    Iterator begin() const {
        return Iterator(data_ + static_cast<uint64_t>(1));
    }

    Iterator end() const {
        return (data_ + static_cast<uint64_t>(n + 1));
    }

    size_t size() const {
        return n;
    }

private:
    size_t n;
    uint64_t* data_;
};
