#include <iostream>
#include <vector>

#pragma once

template<class T>
class FlattenedVector {
public:
    FlattenedVector(std::vector<std::vector<T>>& v_) : v(v_) {
        pref.resize(v.size());
        for (int i = 0; i < v.size(); ++i) {
            if (i == 0) {
                pref[i] = v[i].size();
            } else {
                pref[i] = pref[i - 1] + v[i].size();
            }
        }
    }

    class RandomAccessIterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using difference_type = ptrdiff_t;
        using reference = T&;

        int get_block(const int index) {
            int l = -1, r = FV.v.size() - 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (FV.pref[mid] >= index) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return r;
        }

        explicit RandomAccessIterator(const FlattenedVector& fv, const int index) : FV(fv), CurIndex(index) {}
        explicit RandomAccessIterator(FlattenedVector& fv, int index) : FV(fv), CurIndex(index) {}

        // операторы "доступа"
        T& operator[] (int index) {
            int i = get_block(index);
            int j = index - (i - 1 >= 0 ? FV.pref[i - 1] : 0);
            return FV.v[i][j];
        }
        T& operator*() {
            int i = get_block(CurIndex);
            int j = CurIndex - (i - 1 >= 0 ? FV.pref[i - 1] : 0);
            return FV.v[i][j];
        }

        // операторы "передвижения"
        RandomAccessIterator& operator++() {
            CurIndex++;
            return *this;
        }
        RandomAccessIterator& operator--() {
            CurIndex--;
            return *this;
        }
        RandomAccessIterator operator+(const int value) const {
            return RandomAccessIterator(FV, CurIndex + value);
        }
        RandomAccessIterator operator-(const int value) const {
            return RandomAccessIterator(FV, CurIndex - value);
        }

        // операторы сравнения
        bool operator==(const RandomAccessIterator& other) const {
            return this->FV == other.FV && this->CurIndex == other.CurIndex;
        }
        bool operator!=(const RandomAccessIterator& other) const {
            return !(this->FV == other.FV && this->CurIndex == other.CurIndex);
        }
    private:
        FlattenedVector &FV;
        int CurIndex = 0;
    };


    RandomAccessIterator begin() const {
        return RandomAccessIterator(*this, 0);
    }
    RandomAccessIterator end() const {
        return RandomAccessIterator(*this, pref[v.size()]);
    }

    bool operator==(const FlattenedVector& other) const {
        return this->v == other.v && this->pref == other.pref;
    }
    // friend bool operator==(const FlattenedVector& left, const FlattenedVector& right) const {
    //     return this->v == other.v && this->pref == other.pref;
    // }

    friend std::ostream& operator<<(std::ostream &os, const FlattenedVector& flat_vec) {
        os << "v:\n";
        for (int i = 0; i < flat_vec.v.size(); ++i) {
            for (int j = 0; j < flat_vec.v[i].size(); ++j) {
                os << flat_vec.v[i][j] << " ";
            }
            os << "\n";
        }
        os << "pref = ";
        for (int i = 0; i < flat_vec.pref.size(); ++i) {
            os << flat_vec.pref[i] << " ";
        }
        return os;
    }

private:
    std::vector<std::vector<T>> &v;
    std::vector<int> pref;
};
