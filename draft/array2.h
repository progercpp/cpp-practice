#include <iostream>

class Array {
public:
    Array(std::ostream& ostream) : Ostream_(ostream) {
        size_ = 0;
        capacity_ = 2;
        ostream << "Constructed. Result Array's capacity is 2 and size is 0";
    };
    Array(const Array& array) : Ostream_(array.Ostream_) {
        Copy(array);
        Ostream_ << "Constructed from another Array. Result Array's capacity is " << capacity_ << "and size is " << 2 << ", elements are: ";
        PrintElements(Ostream_);
    }
    Array(size_t size, std::ostream& ostream = std::cout, int defaultValue = 0) : Ostream_(ostream) {
        size_ = size;
        if (size == 0) {
            capacity_ = 2;
        } else {
            capacity_ = size * 2;
        }
        data_ = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = defaultValue;
        }
        Ostream_ << "Constructed with default. Result Array's capacity is " << capacity_ << " and size is " << size_ << ", elements are: ";
        PrintElements(Ostream_);
    }
    // ~Array();
    
    void PrintElements(std::ostream& out) {
        if (size_ >= 1) {
            for (size_t i = 0; i < size_ - 1; ++i) {
                out << data_[i] << ", ";
            }
            out << data_[size_ - 1];
        }
    }
    void Copy(const Array &other) {
        delete[] data_;
        capacity_ = other.capacity_;
        size_ = other.size_;

        if (capacity_ == 0) {
            data_ = nullptr;
            return;
        }

        data_ = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    // size_t Size() const;
    // size_t Capacity() const;
    // void Reserve(size_t newCapacity);
    // void Resize(size_t newSize);
    // void PushBack(int value = 0);
    // void PopBack();
    

    // const int& operator[](const size_t i) const;
    // int& operator[](const size_t i);
    // explicit operator bool() const;

    // bool operator<(const Array& it) const;
    // bool operator>(const Array& it) const;
    // bool operator!=(const Array& it) const;
    // bool operator==(const Array& it) const;
    // bool operator<=(const Array& it) const;
    // bool operator>=(const Array& it) const;

    // Array& operator<<(const int value);
    // Array& operator<<(const Array& it);

    friend std::ostream& operator<<(std::ostream& ostream, const Array& array) {
        ostream << "Result Array's capacity is " << array.capacity_ << " and size is " << array.size_ << ", elements are: ";
        for (size_t i = 0; i < array.size_ - 1; ++i) {
            ostream << array.data_[i] << ", ";
        }
        if (array.size_ >= 1) ostream << array.data_[array.size_ - 1];
        return ostream;
    }

private:
    std::ostream& Ostream_;
    int *data_ = nullptr;
    size_t capacity_ = 0, size_ = 0;
};

