#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
class Vector {
private:
    T* data;                  
    std::size_t size;         
    std::size_t capacity;     

    void resize();            

public:
    Vector();                 
    Vector(const Vector& other); 
    Vector(Vector&& other) noexcept; 
    Vector& operator=(const Vector& other); 
    Vector& operator=(Vector&& other) noexcept; 
    ~Vector();                

    T* get_data();           
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
        delete[] data; 
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
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
std::size_t Vector<T>::get_size() const {
    return size;
}

template <typename T>
std::size_t Vector<T>::get_capacity() const {
    return capacity;
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

template <typename T>
void Vector<T>::increase_size() {
    if (size == capacity) {
        resize();
    }
    ++size;
}

template <typename T>
void Vector<T>::decrease_size() {
    if (size > 0) {
        --size;
    }
}