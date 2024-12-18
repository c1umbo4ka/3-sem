#pragma once
#include "Exercise.h"
#include "Matrix.h"


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
        for (size_t col = 0; col < this->matrix_data.get_cols(); ++col) {
            size_t max_row = 0;
            T max_value = this->matrix_data.get_element(0, col);

            for (size_t row = 1; row < this->matrix_data.get_rows(); ++row) {
                if (this->matrix_data.get_element(row, col) > max_value) {
                    max_value = this->matrix_data.get_element(row, col);
                    max_row = row;
                }
            }

            this->matrix_data.set_element(max_row, col, 0);
        }
    }
};