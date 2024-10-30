#pragma once
#include "Vector.h"
#include <stdexcept>
#include <iostream>

/**
 * @brief Класс Vector
 */
template <typename T>
class VectorOperations {
private:

    /**
    * @brief Класс Vector
    */
    Vector<T> vec;  // Объект Vector<T>

public:

    /**
    * @brief Класс Vector
    */
    VectorOperations();  // Конструктор по умолчанию

    /**
    * @brief Класс Vector
    */
    void push_back(const T& value);
    
    /**
    * @brief Класс Vector
    */
    void pop_back();
    
    /**
    * @brief Класс Vector
    */
    const T back() const;  // Изменено на const T
    
    /**
    * @brief Класс Vector
    */
    void display_vector_state() const;
};

template <typename T>
VectorOperations<T>::VectorOperations() : vec() {}  // Инициализация объекта Vector<T>

template <typename T>
void VectorOperations<T>::push_back(const T& value) {
    vec.increase_size();  // Увеличиваем размер вектора
    vec.get_data()[vec.get_size() - 1] = value;  // Заполняем последний элемент
}

template <typename T>
void VectorOperations<T>::pop_back() {
    vec.decrease_size();  // Удаляем последний элемент
    
}

template <typename T>
const T VectorOperations<T>::back() const {
    if (vec.get_size() > 0) {
        return vec.get_data()[vec.get_size() - 1];  // Возвращаем последний элемент
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
