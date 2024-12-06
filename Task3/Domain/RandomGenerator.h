#pragma once
#include "Generator.h"
#include <random>

/**
 * @brief Класс для генерации случайных чисел в заданном диапазоне.
 */
class random_generator : public Generator {
private:

    /**
    * @brief Диапазон случайных чисел.
    */
    std::uniform_int_distribution<int> distribution;

    /**
    * @brief Генератор случайных чисел.
    */
    std::mt19937 generator;

public:

    /**
     * @brief Конструктор класса random_generator.
     * @param min Минимальное значение диапазона.
     * @param max Максимальное значение диапазона.
     */
    random_generator(int min, int max);

    /**
     * @brief Генерирует случайное число.
     * @return Случайное число в диапазоне [min, max].
     */
    int generate() override;
};

