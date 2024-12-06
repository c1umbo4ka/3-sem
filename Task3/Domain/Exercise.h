#pragma once
#include "Matrix.h"

/**
 * @brief Базовый класс для выполнения задач над матрицей.
 */
class Exercise {
public:

    /**
     * @brief Виртуальный деструктор класса.
     */
    virtual ~Exercise() = default;

    /**
     * @brief Абстрактный метод для выполнения первой задачи.
     * @param matrix Ссылка на объект `Matrix`, над которым выполняется задача.
     */
    virtual void task_1(Matrix& matrix) = 0;

    /**
    * @brief Абстрактный метод для выполнения второй задачи.
    * @param matrix Ссылка на объект `Matrix`, над которым выполняется задача.
    */
    virtual void task_2(Matrix& matrix) = 0;
};


