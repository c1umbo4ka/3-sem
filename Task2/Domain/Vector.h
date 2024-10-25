#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;
    std::size_t size;         
    std::size_t capacity;     

    
    void resize() {
        capacity *= 2;  
        T* new_data = new T[capacity];
        for (std::size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

public:

    Vector() : size(0), capacity(1) {
        data = new T[capacity];  
    }

    ~Vector() {
        delete[] data;  
    }


    void push_back(const T& value) {
        if (size == capacity) {
            resize();  
        }
        data[size] = value;  
        ++size;
    }


    void pop_back() {
        if (size > 0) {
            --size;  
        }
        else {
            std::cout << "Вектор пуст, удаление невозможно." << std::endl;
        }
    }

    T& back() const {
        if (size > 0) {
            return data[size - 1];  
        }
        else {
            throw std::out_of_range("Вектор пуст, доступ невозможен.");
        }
    }
};