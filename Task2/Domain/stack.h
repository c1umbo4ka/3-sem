#pragma once
#include "Vector.h"
#include <stdexcept>
#include <iostream>

/**
 * @brief Класс VectorOperations
 */
template <typename T>
class VectorOperations {
private:

    /**
    * @brief Ссылка на объект vec
    */
    Vector<T> vec; 

public:

    /**
    * @brief Конструктор по умолчанию
    */
    VectorOperations(); 

    /**
    * @brief Функция добавления элемента в конец вектора.
    * @param value Значение, которое будет добавлено в вектор.
    */
    void push_back(const T& value);
    
    /**
    * @brief Функция удаления элемента.
    */
    void pop_back();
    
    /**
    * @brief Возвращает последний элемент вектора.
    * @return Последний элемент вектора.
    */
    const T back() const;
};


template <typename T>
VectorOperations<T>::VectorOperations() : vec() {}  


template <typename T>
void VectorOperations<T>::push_back(const T& value) {
    vec.increase_size();
    vec.get_data()[vec.get_size() - 1] = value;
}

template <typename T>
void VectorOperations<T>::pop_back() {
    vec.decrease_size();    
}

template <typename T>
const T VectorOperations<T>::back() const {
    return vec.get_data()[vec.get_size() - 1];
}
