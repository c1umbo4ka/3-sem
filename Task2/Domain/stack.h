#pragma once
#include "Vector.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class VectorOperations {
private:
    Vector<T>& vec;          

public:
    VectorOperations(Vector<T>& vector); 
    void push_back(const T& value); 
    void pop_back(); 
    T& back() const; 
    void display_vector_state() const; 
};



template <typename T>
VectorOperations<T>::VectorOperations(Vector<T>& vector) : vec(vector) {}

template <typename T>
void VectorOperations<T>::push_back(const T& value) {
    if (vec.get_size() == vec.get_capacity()) {
        vec.increase_size();
    }
    vec.get_data()[vec.get_size()] = value;
    vec.increase_size();
}

template <typename T>
void VectorOperations<T>::pop_back() {
    if (vec.get_size() > 0) {
        vec.decrease_size();
    }
    else {
        std::cout << "Вектор пуст, удаление невозможно." << std::endl;
    }
}

template <typename T>
T& VectorOperations<T>::back() const {
    if (vec.get_size() > 0) {
        return vec.get_data()[vec.get_size() - 1];
    }
    else {
        throw std::out_of_range("Вектор пуст, доступ невозможен.");
    }
}

template <typename T>
void VectorOperations<T>::display_vector_state() const {
    std::cout << "Текущий размер вектора: " << vec.get_size() << "\nСодержимое вектора: ";
    for (std::size_t i = 0; i < vec.get_size(); ++i) {
        std::cout << vec.get_data()[i] << " ";
    }
    std::cout << std::endl;
}
