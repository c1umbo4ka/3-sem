#pragma once
#include <vector>
#include <iostream>

/**
 * @brief Класс, представляющий двумерную матрицу с методами обработки.
 */
class Matrix {
private:

    /**
    * @brief Данные матрицы.
    */
    std::vector<std::vector<int>> data;

    /**
    * @brief Количество строк.
    */
    size_t rows;

    /**
    * @brief Количество столбцов.
    */
    size_t columns;

public:

    /**
     * @brief Конструктор класса Matrix.
     * @param rows Количество строк.
     * @param columns Количество столбцов.
     */
    Matrix(size_t rows, size_t columns);

    /**
     * @brief Заполняет матрицу случайными числами.
     * @param min Минимальное значение диапазона.
     * @param max Максимальное значение диапазона.
     */
    void fill_randomly(int min, int max);

    /**
     * @brief Позволяет пользователю вручную ввести элементы матрицы.
     */
    void fill_from_input();

    /**
     * @brief Доступ к элементу матрицы для чтения/записи.
     * @param row Индекс строки.
     * @param col Индекс столбца.
     * @return Ссылка на элемент матрицы.
     */
    int& operator()(size_t row, size_t col);

    /**
     * @brief Доступ к элементу матрицы только для чтения.
     * @param row Индекс строки.
     * @param col Индекс столбца.
     * @return Константная ссылка на элемент матрицы.
     */
    const int& operator()(size_t row, size_t col) const;

    /**
     * @brief Выводит матрицу на экран.
     */
    void print() const;

    /**
     * @brief Заменяет максимальные элементы каждого столбца на 0.
     */
    void replace_max_in_columns_with_zero();

    /**
     * @brief Вставляет первую строку после строк с максимальным по модулю элементом.
     */
    void insert_first_row_after_max_rows();

    /**
    * @brief Возвращает количество строк.
    * @return Количество строк.
    */
    size_t get_rows() const { return rows; }

    /**
     * @brief Возвращает количество столбцов.
     * @return Количество столбцов.
     */
    size_t get_columns() const { return columns; }
};

