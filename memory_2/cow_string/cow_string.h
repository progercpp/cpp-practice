#include <iostream>

// data
class State {
public:
    State() : ref_count(1), size(0), capacity(2) {
        data = new char[capacity];
    }
    State(State* other) : ref_count(1), size(other->size), capacity(other->capacity) {
        data = new char[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other->data[i];
        }
        other->DeleteRef();
    }
    ~State() {
        // std::cout << "clear succsessfully" << std::endl;
        delete[] data;
    }

    const char& At(size_t index) const {
        return data[index];
    }
    char& operator[] (size_t index) {
        return data[index];
    }

    const char& Back() const {
        return data[size - 1];
    }

    void PushBack(char c) {
        if (size != capacity) {
            data[size] = c;
            size++;
            return;
        }
        size_t nw_capacity = capacity * 2;
        char* nw_data = new char[nw_capacity];
        UpdateData(nw_data, nw_capacity);
        data[size] = c;
        size++;
    }

    size_t Size() const {
        return size;
    }
    size_t Capacity() const {
        return capacity;
    }

    void Reserve(size_t nw_capacity) {
        if (nw_capacity > capacity) {
            char* nw_data = new char[nw_capacity];
            UpdateData(nw_data, nw_capacity);
        }
    }
    void Resize(size_t nw_size) {
        size_t nw_capacity = nw_size;
        char* nw_data = new char[nw_capacity];
        UpdateData(nw_data, nw_capacity);
        size = nw_size;
    }

    void Print() {
        std::cout << "in" << std::endl;
        std::cout << "ref_count = " << ref_count << "\t"; std::cout.flush();
        std::cout << "size = " << size << "\t"; std::cout.flush();
        std::cout << "capacity = " << capacity << "\t"; std::cout.flush();
        std::cout << "ref_count = " << ref_count << "\tsize = " << size << "\tcapacity = " << capacity << std::endl;
        std::cout << "s = ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i];
        }
        std::cout << std::endl;
    }
    bool IsUnique() {
        if (ref_count < 1) while (true) std::cout << "ERROR" << std::endl;
        return ref_count == 1;
    }
    void DeleteRef() {
        ref_count--;
    }
    void AddRef() {
        ref_count++;
    }
private:
    void UpdateData(char* nw_data, size_t nw_capacity) {
        for (size_t i = 0; i < std::min(size, nw_capacity); ++i) {
            nw_data[i] = data[i];
        }
        delete[] data;
        data = nw_data;
        capacity = nw_capacity;
    }
    int ref_count;
    size_t size = 0;
    size_t capacity = 2;
    char* data;
};


class CowString {
public:
    CowString() {
        data = new State();
    }
    CowString(CowString& other) {
        data = other.GiveData();
        data->AddRef();
    }
    CowString& operator=(CowString& other) {
        if (this == &other) return *this;
        if (data->IsUnique()) 
            delete data;
        else
            data->DeleteRef();
        other.GiveData()->AddRef();
        data = other.GiveData();
        return *this;
    }

    const char& At(size_t index) const {
        return data->At(index);
    }
    char& operator[](size_t index) {
        Update();
        return (*data)[index];
    }

    const char& Back() const {
        return data->Back();
    }

    void PushBack(char c) {
        Update();
        data->PushBack(c);
    }

    size_t Size() const {
        return data->Size();
    }
    size_t Capacity() const {
        return data->Capacity();
    }

    void Reserve(size_t capacity) {
        Update();
        data->Reserve(capacity);
    }
    void Resize(size_t size) {
        Update();
        data->Resize(size);
    }

    void Update() {
        // std::cout << "check update\n";
        if (!(data->IsUnique())) {
            // std::cout << "data not unique\n";
            State* nw_data = new State(data);
            data = nw_data;
        }
    }
    ~CowString() {
        // std::cout << "destructor" << std::endl;
        if (data->IsUnique()) {
            // std::cout << "Unique" << std::endl;
            // delete data;
            // data->~State();
            delete data;
        } else {
            // std::cout << "a lot of" << std::endl;
            data->DeleteRef();
        }
    }

    State* GiveData() {
        return data;
    }
    void Print() {
        // std::cout << "pr" << std::endl;
        data->Print();
    }
private:
    State* data;
};
