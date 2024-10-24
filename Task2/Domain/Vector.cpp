#include "vector.h"


template <typename T>
Vector<T>::Vector() : size(0), capacity(1) {
    data = new T[capacity];  
}

// Деструктор
template <typename T>
Vector<T>::~Vector() {
    delete[] data;  
}


template <typename T>
void Vector<T>::resize() {
    capacity *= 2;  
    T* new_data = new T[capacity];  
    for (std::size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];  
    }
    delete[] data;  
    data = new_data;  
}

// Добавление элемента
template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize();  
    }
    data[size] = value;  
    ++size;
}


template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        --size;  
    }
    else {
        std::cout << "Вектор пуст, удаление невозможно." << std::endl;
    }
}


template <typename T>
T& Vector<T>::back() const {
    if (size > 0) {
        return data[size - 1];  
    }
    else {
        throw std::out_of_range("Вектор пуст, доступ невозможен.");
    }
}