#pragma once 
#include <cstddef>
#include <iostream>

/**
* @brief Класс Vector
*/
template <typename T>
class Vector {
private:

    /**
    * @brief Класс Vector
    */
    T* data;
    
    /**
    * @brief Класс Vector
    */
    std::size_t size;
    
    /**
    * @brief Класс Vector
    */
    std::size_t capacity;

    /**
    * @brief Класс Vector
    */
    void resize();

public:
    
    /**
    * @brief Класс Vector
    */
    Vector();
    
    /**
    * @brief Класс Vector
    */
    Vector(const Vector& other);
    
    /**
    * @brief Класс Vector
    */
    Vector(Vector&& other) noexcept;
    
    /**
    * @brief Класс Vector
    */
    Vector& operator=(const Vector& other);
    
    /**
    * @brief Класс Vector
    */
    Vector& operator=(Vector&& other) noexcept;
    
    /**
    * @brief Класс Vector
    */
    ~Vector();

    T* get_data();
    const T* get_data() const;  // Новый метод для получения данных в константном контексте
    std::size_t get_size() const;
    std::size_t get_capacity() const;
    void increase_size();
    void decrease_size();
};

template <typename T>
Vector<T>::Vector() : size(0), capacity(1) {
    data = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (std::size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        Vector temp(other); // Используем copy & swap
        std::swap(data, temp.data);
        std::swap(size, temp.size);
        std::swap(capacity, temp.capacity);
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
T* Vector<T>::get_data() {
    return data;
}

template <typename T>
const T* Vector<T>::get_data() const { // Определение метода для получения данных в константном контексте
    return data;
}

template <typename T>
std::size_t Vector<T>::get_size() const {
    return size;
}

template <typename T>
std::size_t Vector<T>::get_capacity() const {
    return capacity;
}

template <typename T>
void Vector<T>::resize() {
    // Создаем временный объект Vector с увеличенной емкостью
    Vector temp;
    temp.capacity = capacity * 2; // Увеличиваем емкость
    temp.data = new T[temp.capacity]; // Выделяем память под новые данные

    // Копируем старые данные в новый массив
    for (std::size_t i = 0; i < size; ++i) {
        temp.data[i] = data[i];
    }
    temp.size = size; // Устанавливаем размер

    // Обмен данных между временным и текущим объектом
    std::swap(data, temp.data);
    std::swap(size, temp.size);
    std::swap(capacity, temp.capacity);
}

template <typename T>
void Vector<T>::increase_size() {
    if (size == capacity) {
        resize();
    }
    data[size++] = T(); // Default initialize the new element
}

template <typename T>
void Vector<T>::decrease_size() {
    if (size > 0) {
        --size;
        std::cout << "Последний элемент удален.\n";
    }
    else {
        std::cout << "Вектор пуст. Удаление невозможно.\n";
    }
}
