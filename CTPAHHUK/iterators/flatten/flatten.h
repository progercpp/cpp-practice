#include <iostream>
#include <vector>

#pragma once

template<class T>
class FlattenedVector {
public:
    FlattenedVector(std::vector<std::vector<T>>& v_) : v(v_) {
        // std::cout << "start constructor" << std::endl;
        pref.resize(v.size());
        
        for (int i = 0; i < int(v.size()); ++i) {
            if (i == 0) {
                pref[i] = int(v[i].size());
            } else {
                pref[i] = pref[i - 1] + int(v[i].size());
            }
        }
        // std::cout << "end constructor" << std::endl;
    }

    class RandomAccessIterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using difference_type = ptrdiff_t;
        using reference = T&;

        int get_block(int index) const {
            int l = -1, r = int(FV.v.size()) - 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (FV.pref[mid] >= index) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return r;
            // if (FV.pref[r] >= index && (r - 1 >= 0 && FV.pref[r - 1] < index || r == 0)) return r;
            // else {
            //     std::cout << "ERROR\n"; std::cout.flush();
            //     while (true) {};
            //     // exit(0);
            // }
        }

        explicit RandomAccessIterator(FlattenedVector& fv, int index) : FV(fv), CurIndex(index) {}
        RandomAccessIterator& operator=(RandomAccessIterator& other) {
            // other.FV = this->FV;
            // other.CurIndex = this->CurIndex;
            // return other;
            this->FV = other.FV;
            this->CurIndex = other.CurIndex;
            return *this;
        }

        // операторы доступа
        T& operator[] (const int index) {
            int i = get_block(index + 1 + CurIndex);
            int j = index + CurIndex - (i - 1 >= 0 ? FV.pref[i - 1] : 0);
            return FV.v[i][j];
        }
        T& operator[] (const int index) const {
            int i = get_block(index + 1 + CurIndex);
            int j = index + CurIndex - (i - 1 >= 0 ? FV.pref[i - 1] : 0);
            return FV.v[i][j];
        }   
        T& operator*() const {
            // std::cout << "operator* const\tCur_index = " << CurIndex << "\n"; std::cout.flush();

            int i = get_block(CurIndex + 1);
            int j = CurIndex - (i - 1 >= 0 ? FV.pref[i - 1] : 0);
            return FV.v[i][j];
        }
        T& operator*() {
            // std::cout << "operator*\tCur_index = " << CurIndex << "\n"; std::cout.flush();
            int i = get_block(CurIndex + 1);
            int j = CurIndex - (i - 1 >= 0 ? FV.pref[i - 1] : 0);
            return FV.v[i][j];
        }

        // арифметические действия
        RandomAccessIterator& operator++() {
            // std::cout << "Operator++\n"; std::cout.flush();
            CurIndex++;
            return *this;
        }
        RandomAccessIterator& operator--() {
            // std::cout << "Operator--\n"; std::cout.flush();
            CurIndex--;
            return *this;
        }
        RandomAccessIterator operator+(const int value) const {
            return RandomAccessIterator(FV, CurIndex + value);
        }
        friend RandomAccessIterator operator+(const 
        int& left, const RandomAccessIterator& right) {
            return RandomAccessIterator(right.FV, right.CurIndex + left);
        }
        RandomAccessIterator operator-(const int value) const {
            return RandomAccessIterator(FV, CurIndex - value);
        }
        RandomAccessIterator& operator+=(const int value) {
            this->CurIndex += value;
            return *this;
        }
        RandomAccessIterator& operator-=(const int value) {
            this->CurIndex -= value;
            return *this;
        }
        int operator-(const RandomAccessIterator& other) const {
            return this->CurIndex - other.CurIndex;
        }
        RandomAccessIterator operator+(const RandomAccessIterator& other) const {
            return RandomAccessIterator(this->FV, this->CurIndex + other.CurIndex);
        }


        // операторы сравнения
        bool operator==(const RandomAccessIterator& other) const {
            // return this == &other;
            return this->CurIndex == other.CurIndex;
            // return this->CurIndex == other.CurIndex && &this->FV.v == &other.FV.v && &this->FV.pref == &other.FV.pref;
        }
        bool operator!=(const RandomAccessIterator& other) const {
            // return this != &other;
            return this->CurIndex != other.CurIndex;
            // return !(this->CurIndex == other.CurIndex && &this->FV.v == other.FV.v && &this->FV.pref == &other.FV.pref);
        }
        bool operator<=(const RandomAccessIterator& other) const {
            return this->CurIndex <= other.CurIndex;
        }
        bool operator>(const RandomAccessIterator& other) const {
            return this->CurIndex > other.CurIndex;
        }
        bool operator<(const RandomAccessIterator& other) const {
            return this->CurIndex < other.CurIndex;
        }

    private:
        FlattenedVector &FV;
        int CurIndex = 0;
    };


    RandomAccessIterator begin() {
        // std::cout << "take begin\n"; std::cout.flush();
        return RandomAccessIterator(*this, 0);
    }
    RandomAccessIterator end() {
        // std::cout << "take end\n"; std::cout.flush();
        return RandomAccessIterator(*this, (int(v.size()) - 1 >= 0 ? pref[int(v.size()) - 1] : 0));
    }

    bool operator==(FlattenedVector& other) {
        return this == &other;
        // return &this->v == &other.v && &this->pref == &other.pref;
    }
    FlattenedVector& operator=(FlattenedVector& other) {
        other.v = this->v;
        other.pref = this->pref;
        return other;
    }

    // для дебага класса FlattenedVector
    friend std::ostream& operator<<(std::ostream &os, const FlattenedVector& flat_vec) {
        os << "v:\n";
        os << "v.size() = " << int(flat_vec.v.size()) << "\n";
        for (int i = 0; i < int(flat_vec.v.size()); ++i) {
            // os << int(flat_vec.v[i].size()) << "\n";
            for (int j = 0; j < int(flat_vec.v[i].size()); ++j) {
                os << flat_vec.v[i][j] << " ";
            }
            os << "\n";
        }
        os << "pref = ";
        for (int i = 0; i < int(flat_vec.pref.size()); ++i) {
            os << flat_vec.pref[i] << " ";
        }
        return os;
    }

private:
    std::vector<std::vector<T>> &v;
    std::vector<int> pref;
};
