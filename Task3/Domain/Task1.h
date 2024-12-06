#pragma once
#include "Exercise.h"

/**
 * @brief Класс для выполнения первой задачи: замена максимальных элементов столбцов на 0.
 */
class Task1 : public Exercise {
public:

    /**
     * @brief Реализация первой задачи.
     * @param matrix Матрица, на которой выполняется задача.
     */
    void task_1(Matrix& matrix) override {
        matrix.replace_max_in_columns_with_zero();
    }

    /**
     * @brief Заглушка для второй задачи (не реализована в Task1).
     * @param matrix Матрица (не используется).
     */
    void task_2(Matrix& matrix) override {
    }
};

