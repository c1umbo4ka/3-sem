#pragma once
#include "Matrix.h"
#include <functional>

/**
 * @brief Абстрактный базовый класс Exercise
 * @tparam T Тип данных для элементов матрицы.
 */
template <typename T>
class exercise {
public:

    /**
     * @brief Матрица, с которой работает упражнение.
     */
    matrix<T> matrix_data;

    /**
    * @brief Конструктор класса Exercise.
    * @param rows Количество строк в матрице.
    * @param cols Количество столбцов в матрице.
    */
    exercise(int rows, int cols) : matrix_data(rows, cols) {}

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~exercise() = default;

    /**
     * @brief Чисто виртуальная функция, которая определяет основную задачу упражнения.
     */
    virtual void perform_task() = 0;

    /**
     * @brief Заполняет матрицу с помощью переданной функции-генератора.
     * @param generator Функция-генератор, возвращающая элементы матрицы.
     */
    void fill(const std::function<T()>& generator) {
        matrix_data.fill(generator);
    }

    /**
     * @brief Печатает матрицу на экран.
     */
    void print() const {
        matrix_data.print();
    }
};
