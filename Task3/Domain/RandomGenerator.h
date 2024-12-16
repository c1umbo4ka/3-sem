#pragma once
#include <random>

/**
* @brief Генератор случайных чисел.
* @tparam T Тип сгенерированных значений.
*/
template <typename T>
class random_generator {
private:

    /**
    * @brief Генератор случайных чисел.
    */
    std::mt19937 generator;

    /**
    * @brief Диапазон значений для генерации.
    */
    std::conditional_t<
        std::is_floating_point_v<T>,
        std::uniform_real_distribution<T>,
        std::uniform_int_distribution<T>
    > distribution;

public:

    /**
    * @brief Конструктор генератора случайных чисел.
    * @param min Минимальное значение.
    * @param max Максимальное значение.
    */
    random_generator(T min, T max)
        : generator(std::random_device{}()), distribution(min, max) {}

    /**
    * @brief Генерирует случайное значение в заданном диапазоне.
    * @return Случайное значение.
    */
    T generate() {
        return distribution(generator);
    }
};



