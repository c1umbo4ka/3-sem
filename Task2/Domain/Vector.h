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
    * @brief Указатель на массив элементов.
    */
    T* data;
    
    /**
    * @brief Текущий размер вектора
    */
    std::size_t size;
    
    /**
    * @brief Вместимость вектора.
    */
    std::size_t capacity;

    /**
    * @brief Функция емкости вектора вдвое.
    */
    void resize();

public:
    
    /**
    * @brief Конструктор по умолчанию.
    */
    Vector();
    
    /**
    * @brief Конструктор копирования, создает новый вектор, копируя данные из другого вектора.
    * @param other Вектор, из которого будут скопированы данные.
    */
    Vector(const Vector& other);
    
    /**
    * @brief Конструктор перемещения.
    * @param other Вектор, данные из которого будут перемещены.
    */
    Vector(Vector&& other) noexcept;
    
    /**
    * @brief Оператор копирования.
    * @param other Вектор, из которого будут скопированы данные.
    * @return Ссылка на текущий объект.
    */
    Vector& operator=(const Vector& other);
    
    /**
    * @brief Оператор перемещения.
    * @param other Вектор, данные из которого будут перемещены.
    * @return Ссылка на текущий объект.
    */
    Vector& operator=(Vector&& other) noexcept;
    
    /**
    * @brief Деструктор.
    */
    ~Vector();

    /**
    * @brief Функция возврата указателя на данные вектора.
    * @return Указатель на массив данных.
    */
    T* get_data();

    /**
    * @brief Функция возврата констанстного указателя на данные вектора.
    * @return Указатель на массив данных.
    */
    const T* get_data() const; 
    
    /**
    * @brief Функция возврата размера вектора.
    * @return Текущий размер вектора.
    * @throws std::out_of_range Если вектор пуст, выбрасывается исключение.
    */
    std::size_t get_size() const;

    /**
    * @brief Функция возврата вместимости вектора.
    * @return Текущая вместимость вектора.
    */
    std::size_t get_capacity() const;

    /**
    * @brief Класс Vector
    */
    void increase_size();

    /**
    * @brief Класс Vector
    * @throws std::out_of_range Если вектор пуст, выбрасывается исключение.
    */
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
        Vector temp(other); 
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
const T* Vector<T>::get_data() const {
    return data;
}


template <typename T>
std::size_t Vector<T>::get_size() const {
    if (size > 0) {
        return size;
    }
    else {
        throw std::out_of_range("Вектор пуст, доступ невозможен.");
    }
}


template <typename T>
std::size_t Vector<T>::get_capacity() const {
    return capacity;
}


template <typename T>
void Vector<T>::resize() {
    Vector temp;
    temp.capacity = capacity * 2; 
    temp.data = new T[temp.capacity]; 

    for (std::size_t i = 0; i < size; ++i) {
        temp.data[i] = data[i];
    }
    temp.size = size; 

    std::swap(data, temp.data);
    std::swap(size, temp.size);
    std::swap(capacity, temp.capacity);
}

template <typename T>
void Vector<T>::increase_size() {
    if (size == capacity) {
        resize();
    }
    data[size++] = T(); 
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
