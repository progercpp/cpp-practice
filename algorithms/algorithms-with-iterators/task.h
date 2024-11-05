#include <cstdlib>
#include <iterator>
#include <iostream>

template<class InputIt, class OutputIt, class UnaryOperation>
void Transform(InputIt firstIn, InputIt lastIn, OutputIt firstOut, UnaryOperation op) {
    auto res = firstOut;
    for (auto iter = firstIn; iter < lastIn; ++iter, ++res) {
        *res = op(*iter);
    }
}


template<class BidirIt, class UnaryPredicate>
void Partition(BidirIt first, BidirIt last, UnaryPredicate p) {
    int cnt = 0;
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


/*
 * Напишите класс "диапазон чисел Фибоначчи"
 * Экземпляр класса представляет из себя диапазон от первого до N-го числа Фибоначчи (1, 2, 3, 5, 8, 13 и т.д.)
 * С помощью функций begin и end можно получить итераторы и пробежать по диапазону или передать их в STL-алгоритмы
 */
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

        value_type operator *() const {
            // разыменование итератора -- доступ к значению
        }

        Iterator& operator ++() {
            // prefix increment
        }

        Iterator operator ++(int) {
            // postfix increment
        }

        bool operator ==(const Iterator& rhs) const {
        }

        bool operator <(const Iterator& rhs) const {
        }
    };

    FibonacciRange(size_t amount) {}

    Iterator begin() const {
    }

    Iterator end() const {
    }

    size_t size() const {
    }
};
