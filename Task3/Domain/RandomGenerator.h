#pragma once
#include "Generator.h"
#include <random>

/**
* @brief Генератор случайных чисел.
* @tparam T Тип сгенерированных значений.
*/
template <typename T>
class random_generator : public generator<T> {
private:

    /**
    * @brief Генератор случайных чисел.
    */
    std::mt19937 generator;

    /**
    * @brief Диапазон значений для генерации.
    */
    std::conditional<
        std::is_floating_point<T>::value,
        std::uniform_real_distribution<T>,
        std::uniform_int_distribution<T>
    >::type distribution;

public:

    /**
    * @brief Конструктор генератора случайных чисел.
    * @param min Минимальное значение.
    * @param max Максимальное значение.
    */
    random_generator(T min, T max);

    /**
    * @brief Генерирует случайное значение в заданном диапазоне.
    * @return Случайное значение.
    */
    T generate() override;
};

template <typename T>
random_generator<T>::random_generator(T min, T max)
    : generator(std::random_device{}()), distribution(min, max) {}

template <typename T>
T random_generator<T>::generate() {
    return distribution(generator);
}