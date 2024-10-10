#include <iostream>

class Array {
public:
    void RewriteOstream() {
        Ostream_ << "blablabla" << '\n';
    }
    Array(std::ostream& ostream) : Ostream_(ostream) {
        size_ = 0;
        capacity_ = 2;
        data_ = new int[2];
        Ostream_ << "Constructed. Result Array's capacity is " << capacity_ << " and size is " << size_;
    };
    Array(const Array& array) : Ostream_(array.Ostream_) {
        Copy(array);
        Ostream_ << "Constructed from another Array. Result Array's capacity is " << capacity_ << "and size is " << size_ << ", elements are: ";
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

    // Не возвращается нормально
    ~Array() {
        Ostream_ << "\nDestructed " << size_ << '\n';
        delete[] data_;
        size_ = 0;
        capacity_ = 0;
    }
    
    void PrintElements(std::ostream& out) {
        if (size_ >= 1) {
            for (size_t i = 0; i < size_ - 1; ++i) {
                out << data_[i] << ", ";
            }
            out << data_[size_ - 1];
        }
        out << "\n";
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
