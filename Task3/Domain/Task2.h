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
        T max_abs_value = get_max_abs_value();
        for (int i = 0; i < this->matrix.get_rows(); ++i) {
            if (contains_max_abs_value(i, max_abs_value)) {
                insert_row_after(i, this->matrix.get_row(0));
                ++i;
            }
        }
    }

private:

    /**
    * @brief Получает максимальное по модулю значение.
    */
    T get_max_abs_value() const {
        T maxAbs = 0;
        for (int row = 0; row < this->matrix.get_rows(); ++row) {
            for (int col = 0; col < this->matrix.get_cols(); ++col) {
                maxAbs = std::max(maxAbs, std::abs(this->matrix.get_element(row, col)));
            }
        }
        return maxAbs;
    }

    /**
    * @brief Проверяет, есть  ли в строке макстмальное по модулю начение.
    * @param row Индекс строки.
    * @param max_abs_value Максимальное по модулю значение.
    * @return true, если строка содержит это значение.
    */
    bool contains_max_abs_value(int row, T max_abs_value) const {
        const auto& currentRow = this->matrix.get_row(row);
        return std::find(currentRow.begin(), currentRow.end(), max_abs_value) != currentRow.end();
    }

    /**
    * @brief Вставляет строку после указанной.
    * @param index Индекс строки.
    * @param row Вектор , представляющий вставляемую строку.
    */
    void insert_row_after(int index, const std::vector<T>& row) {
        this->matrix.insert_row(index + 1, row);
    }
};