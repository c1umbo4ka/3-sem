#pragma once
#include "Exercise.h"
#include "Matrix.h"
#include <cmath>

/**
* @brief Задача 2 - Вставить первую строку после строки, содержащей макстмальный по модулю элемент.
* @tparam T Тип элементов матрицы.
*/
template <typename T>
class Task2 : public exercise<T> {
public:

    /**
    * @brief Конструктор задачи.
    * @param rows Количество строк в матрице.
    * @param cols Количество столбцов в матрице.
    */
    using exercise<T>::exercise;

    /**
    * @brief Выполняет задачу 2.
    */
    void perform_task() override {
        T max_value = find_max_element();
        for (int i = 0; i < this->matrix_data.get_rows(); ++i) {
            if (contains_max_element_in_row(i, max_value)) {
                insert_first_row_after(i);
                ++i; 
            }
        }
    }

private:

    /**
    * @brief Получает максимальное по модулю значение.
    */
    T find_max_element() {
        T max_value = this->matrix_data.get_element(0, 0);

        for (size_t row = 0; row < this->matrix_data.get_rows(); ++row) {
            for (int col = 0; col < this->matrix_data.get_cols(); ++col) {
                T current_value = this->matrix_data.get_element(row, col);
                if (current_value > max_value) {
                    max_value = current_value;
                }
            }
        }

        return max_value;
    }

    /**
    * @brief Проверяет, есть  ли в строке макстмальное по модулю начение.
    * @param row Индекс строки.
    * @param max_abs_value Максимальное по модулю значение.
    * @return true, если строка содержит это значение.
    */
    bool contains_max_element_in_row(int row_index, T max_value) {
        const auto& row = this->matrix_data.get_row(row_index);
        return std::find(row.begin(), row.end(), max_value) != row.end();
    }

    /**
    * @brief Вставляет первую после указанной.
    * @param index Индекс строки.
    * @param row Вектор , представляющий вставляемую строку.
    */
    void insert_first_row_after(int row_index) {
        std::vector<T> first_row = this->matrix_data.get_row(0);  
        this->matrix_data.insert_row(row_index + 1, first_row);  
    }
};