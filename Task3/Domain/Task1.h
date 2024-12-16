#pragma once
#include "Exercise.h"
#include "Matrix.h"
#include <algorithm>

/**
* @brief Задача 1 - заменить максимальные элементы столбцов на 0.
* @tparam T Тип элементов матрицы.
*/
template <typename T>
class Task1 : public exercise<T> {
public:

    /**
    * @brief Конструктор задачи.
    * @param rows Количество строк в матрице.
    * @param cols Количество столбцов в матрице.
    */
    using exercise<T>::exercise;

    /**
    * @brief Выполняет задачу 1.
    */
    void perform_task() override {
        for (int col = 0; col < this->matrix.get_cols(); ++col) {
            replace_max_in_column_with_zero(col);
        }
    }

private:

    /**
    * @brief Заменяет Максимальные элементы столбцов на 0.
    * @param col Номер столбца.
    */
    void replace_max_in_column_with_zero(int col) {
        int maxRow = 0;
        T maxValue = this->matrix.get_element(0, col);
        for (int row = 1; row < this->matrix.get_rows(); ++row) {
            if (this->matrix.get_element(row, col) > maxValue) {
                maxValue = this->matrix.get_element(row, col);
                maxRow = row;
            }
        }
        this->matrix.set_element(maxRow, col, 0);
    }
};