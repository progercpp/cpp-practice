#include <iostream>

template <typename T> // template<class T> это то же самое
class Vector {
public:
  Vector() {} // конструктор по умолчанию
  ~Vector() { delete[] data_; }

  // конструктор копирования
  Vector(const Vector &other) : capacity_(other.size_), size_(other.size_) {
    Copy(other);
  }

  // оператор присваивания
  Vector &operator=(const Vector &other) {
    Copy(other);
    return *this;
  }

  void PushBack(T value) {
    if (size_ == capacity_) {
      capacity_ *= 2;
      if (capacity_ == 0) {
        capacity_ = 1;
      }
      auto new_data = new T[capacity_];
      for (int i = 0; i < size_; i++) {
        new_data[i] = data_[i];  // Work In Progress
      }
      delete[] data_;
      data_ = new_data;
    }
    data_[size_] = std::move(value);
    ++size_;
  }

  T &At(size_t index) { return GetReference(index); }

  T &operator[](size_t index) { return data_[index]; }

  const T &At(size_t index) const { return GetReference(index); }

  const T &operator[](size_t index) const { return data_[index]; }

  size_t Size() const { return size_; }

  size_t Capacity() const { return capacity_; }

  bool Empty() const { return size_ == 0; }

private:
  T *data_ = nullptr;
  size_t capacity_ = 0, size_ = 0;

  void Copy(const Vector &other) {
    delete[] data_;
    capacity_ = other.size_;
    size_ = other.size_;

    if (capacity_ == 0) {
      data_ = nullptr;
      return;
    }

    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; i++) {
      data_[i] = other.data_[i];
    }
  }

  int &GetReference(size_t index) const {
    static T emptyValue = -1;
    if (index >= size_) {
      // мы не знаем пока про исключения, поэтому возвращаем значение-заглушку
      return emptyValue;
    }
    return data_[index];
  }
};

class Foo {
public:
  Foo() = default; // просим сгенерировать такой конструктор, который был бы
                   // сгенерирован компилятором по-умолчанию
  Foo(const Foo &) = delete; // просим не генерировать такой конструктор
  explicit Foo(int value) {
    for (int i = 0; i < 10000; i++) {
      values_[i] = value;
    }
  }

  ~Foo() { delete[] values_; }

  Foo &operator=(const Foo &) = delete; // просим не генерировать оператор =
  Foo &operator=(Foo &&other) {
    std::swap(values_, other.values_);
    return *this;
  }

  void PrintValue() const { std::cout << values_[0] << std::endl; }

private:
  int *values_ = new int[10000];
};

int main() {
  const Vector<int> v; // вызывается конструктор по умолчанию
  Vector<int> b = v; // вызывается конструктор копирования
  Vector<int> c(b);  // вызывается конструктор копирования

  c = b;  // вызывается оператор присваивания

  Vector<Vector<int>> d;
  d.PushBack(Vector<int>());
  d[0].PushBack(1);

  std::cout << d[0][0] << std::endl;

  Vector<Foo> f;
  f.PushBack(Foo(10));

  return 0;
}



// Array::Array(size_t size, std::ostream& ostream, int defaultValue) : Ostream_(ostream) {
//     size_ = size;
//     capacity_ = size * 2;
//     data_ = new int[capacity_];
//     for (size_t i = 0; i < size; ++i) {
//         data_[i] = defaultValue;
//     }

//     Ostream_ << "Constructed with default. Result Array's capacity is " << capacity_ << " and size is " << size_;

//     if (size_) {
//         Ostream_ << ", elements are: ";
//         for (size_t i = 0; i < size_ - 1; ++i) {
//             Ostream_ << data_[i] << ", ";
//         }
//         Ostream_ << data_[size_ - 1];
//     }

//     Ostream_ << '\n';
// }


// std::ostream& operator<<(std::ostream& ostream, const Array& array) {
//     ostream << "Result Array's capacity is " << array.capacity_ << " and size is " << array.size_;
//     if (array.size_) {
//         ostream << ", elements are: ";
//         for (size_t i = 0; i < array.size_ - 1; ++i) {
//             ostream << array.data_[i] << ", ";
//         }
//         ostream << array.data_[array.size_ - 1];
//     }
//     return ostream;
// }
