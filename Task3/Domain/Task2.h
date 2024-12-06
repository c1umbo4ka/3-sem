#pragma once
#include "Exercise.h"

/**
 * @brief Выполнение второй задачи.
 */
class Task2 : public Exercise {
public:

    /**
     * @brief Заглушка для первой задачи.
     * @param matrix Матрица (не используется в Task2).
     */
    void task_1(Matrix& matrix) override {
    }

    /**
    * @brief Выполнение второй задачи.
    * @param matrix Матрица для обработки.
    */
    void task_2(Matrix& matrix) override {
        matrix.insert_first_row_after_max_rows();
    }
};


