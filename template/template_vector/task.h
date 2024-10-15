#include <cstdint>
#include <iostream>
#include <iostream>

template<class T>
T min(T a, T b) {
    if (a < b) {
        return a;
    }
    return b;
}
template<class T>
T max(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

template<class T>
class Array {
public:
    Array(std::ostream& ostream) : Ostream_(ostream) {
        size_ = 0;
        capacity_ = 2;
        data_ = new T[2];
        Ostream_ << "Constructed. Result Array's capacity is " << capacity_ << " and size is " << size_ << '\n';
    };
    Array(const Array& array) : Ostream_(array.Ostream_) {
        Copy(array);
        Ostream_ << "Constructed from another Array. Result Array's capacity is " << capacity_ << " and size is " << size_;
        if (size_ >= 1) {
            Ostream_ << ", elements are: ";
            PrintElements(Ostream_);
        }
        Ostream_ << '\n';
    }
    Array(size_t size, std::ostream& ostream = std::cout, T defaultValue) : Ostream_(ostream) {
        size_ = size;
        if (size == 0) {
            capacity_ = 2;
        } else {
            capacity_ = size * 2;
        }
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = defaultValue;
        }
        Ostream_ << "Constructed with default. Result Array's capacity is " << capacity_ << " and size is " << size_;
        if (size_ >= 1) {
            Ostream_ << ", elements are: ";
            PrintElements(Ostream_);
        }
        Ostream_ << '\n';
    }
    ~Array() {
        Ostream_ << "Destructed " << size_ << '\n';
        delete[] data_;
    }

    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return capacity_;
    }
    void Reserve(size_t newCapacity) {
        if (newCapacity > capacity_) {
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < size_; ++i) {
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
            capacity_ = newCapacity;
        }
    }
    void Resize(size_t newSize) {
        if (capacity_ < newSize) {
            T* newData = new T[newSize];
            for (size_t i = 0; i < newSize; ++i) {
                if (i < size_) {
                    newData[i] = data_[i];
                } else {
                    // newData[i] = 0;
                }
            }
            delete[] data_;
            data_ = newData;
        }
        size_ = newSize;
        capacity_ = max(capacity_, newSize);
    }
    void PopBack() {
        if (size_ >= 1) {
            size_--;
        }
    }
    void PushBack(T value) {
        if (size_ == capacity_) {
            capacity_ *= 2;
            T* newData = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
        }
        data_[size_] = value;
        size_++;
    }
    
    void PrintElements(std::ostream& out) {
        if (size_ >= 1) {
            for (size_t i = 0; i < size_ - 1; ++i) {
                out << data_[i] << ", ";
            }
            out << data_[size_ - 1];
        }
    }
    void Copy(const Array &other) {
        capacity_ = other.capacity_;
        size_ = other.size_;

        if (capacity_ == 0) {
            data_ = nullptr;
            return;
        }

        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    const T& operator[](const size_t i) const {
        return data_[i];
    }
    T& operator[](const size_t i) {
        return data_[i];
    }

    explicit operator bool() const {
        if (size_) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<(const Array& it) const {
        for (size_t i = 0; i < min(size_, it.size_); ++i) {
            if (data_[i] < it.data_[i]) {
                return true;
            }
            if (data_[i] > it.data_[i]) {
                return false;
            }
        }
        if (size_ < it.size_) {
            return true;
        }
        return false;
    }
    bool operator>(const Array& it) const {
        for (size_t i = 0; i < min(size_, it.size_); ++i) {
            if (data_[i] > it.data_[i]) {
                return true;
            }
            if (data_[i] < it.data_[i]) {
                return false;
            }
        }
        if (size_ > it.size_) {
            return true;
        }
        return false;
    }
    
    bool operator!=(const Array& it) const {
        if (size_ != it.size_) return true;
        for (size_t i = 0; i < min(size_, it.size_); ++i) {
            if (data_[i] != it.data_[i]) return true;
        }
        return false;
    }
    bool operator==(const Array& it) const {
        if (size_ != it.size_) return false;
        for (size_t i = 0; i < min(size_, it.size_); ++i) {
            if (data_[i] != it.data_[i]) return false;
        }
        return true;
    }
    bool operator<=(const Array& it) const {
        for (size_t i = 0; i < min(size_, it.size_); ++i) {
            // if (data_[i] == it.data_[i]) return true;
            if (data_[i] < it.data_[i]) {
                return true;
            }
            if (data_[i] > it.data_[i]) {
                return false;
            }
        }
        if (size_ <= it.size_) {
            return true;
        }
        return false;
    }
    bool operator>=(const Array& it) const {
        for (size_t i = 0; i < min(size_, it.size_); ++i) {
            // if (data_[i] == it.data_[i]) return true;
            if (data_[i] > it.data_[i]) {
                return true;
            }
            if (data_[i] < it.data_[i]) {
                return false;
            }
        }
        // префикс data_[0..minsize - 1] и it.data_[0..minsize - 1] равны
        if (size_ >= it.size_) {
            return true;
        }
        return false;
    }

    Array& operator<<(const T value) {
        this->PushBack(value);
        // return this->Array;
        return *this;
    }
    Array& operator<<(const Array& it) {
        T* newData = new T[size_ + it.size_];
        for (size_t i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        for (size_t i = 0; i < it.size_; ++i) {
            newData[i + size_] = it.data_[i];
        }
        delete[] data_;
        data_ = newData;
        size_ += it.size_;
        capacity_ = size_;
        return *this;
    }
    
    void Clear() {
        delete[] data_;
        capacity_ = 2;
        size_ = 0;
        data_ = new T[capacity_];
    }
    bool Insert(size_t pos, const T& value) {
        if (pos > Size()) {
            return false;
        }
        T val = value;
        if (pos == Size()) {
            PushBack(val);
            return true;
        }
        
        PushBack(val);
        for (size_t i = size_ - 1; i >= pos + 1; --i) {
            data_[i] = data_[i - 1];
        }
        data_[pos] = value;
        return true;
    }

    bool Erase(size_t pos) {
        if (pos >= Size()) {
            return false;
        }
        for (size_t i = pos; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        size_--;
        return true;
    }

    friend std::ostream& operator<<(std::ostream& ostream, const Array& array) {
        ostream << "Result Array's capacity is " << array.capacity_ << " and size is " << array.size_;
        if (array.size_ >= 1) {
            ostream << ", elements are: ";
            for (size_t i = 0; i < array.size_ - 1; ++i) {
                ostream << array.data_[i] << ", ";
            }
            ostream << array.data_[array.size_ - 1];
        }
        return ostream;
    }

private:
    std::ostream& Ostream_;
    T *data_;
    size_t capacity_ = 2, size_ = 0;
};
