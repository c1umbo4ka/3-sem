#pragma once
#include <vector>
#include <iostream>
#include <functional>

/**
 * @brief Класс матрицы
 * @tparam T Тип элементов матрицы.
 */
template <typename T>
class matrix {
private:

    /**
     * @brief Двумерный вектор для хранения элементов матрицы.
     */
    std::vector<std::vector<T>> matrix_data;

    /**
     * @brief Количество строк в матрице.
     */
    int rows;

    /**
     * @brief Количество столбцов в матрице.
     */
    int cols;

public:
    /**
     * @brief Конструктор матрицы.
     * @param rows Количество строк.
     * @param cols Количество столбцов.
     */
    matrix(int rows, int cols);

    /**
     * @brief Заполняет матрицу значениями, сгенерированными переданной функцией.
     * @param generator Функция-генератор элементов.
     */
    void fill(const std::function<T()>& generator);

    /**
     * @brief Печатает матрицу на экран.
     */
    void print() const;

    /**
     * @brief Возвращает строку матрицы по индексу
     * @param index Индекс строки.
     * @return Вектор элементов строки.
     */
    const std::vector<T>& get_row(int index) const;

    /**
    * @brief Получает количество строк в матрице.
    * @return Количество строк в матрице.
    */
    int get_rows() const { return rows; }

    /**
    * @brief Получает количество столбцов в матрице.
    * @return Количество столбцов в матрице.
    */
    int get_cols() const { return cols; }

    /**
    * @brief Получает элемент матрицы по указанным индексам строки и столбца.
    * @param row Индекс строки (начиная с 0).
    * @param col Индекс столбца (начиная с 0).
    * @return Значение элемента типа T, расположенного в строке row и столбце col
    * @throws std::out_of_range Если индекс строки или столбца выходит за пределы размеров матрицы.
    */
    T get_element(int row, int col) const { return matrix_data[row][col]; }

    /**
    * @brief Устанавливает значение элемента матрицы по указанным индексам строки и столбца.
    * @param row Индекс строки (начиная с 0).
    * @param col Индекс столбца (начиная с 0).
    * @param value Новое значение элемента типа T, которое будет установлено в строку row и столбец col
    * @throws std::out_of_range Если индекс строки или столбца выходит за пределы размеров матрицы.
    */
    void set_element(int row, int col, T value) { matrix_data[row][col] = value; }

    /**
     * @brief Вставляет новую строку в матрицу
     * @param index Индекс, куда вставляется строка.
     * @param row Вектор элементов новой строки.
     */
    void insert_row(int index, const std::vector<T>& row);

    /**
     * @brief Доступ к элементу по индексу.
     * @param row Номер строки.
     * @param col Номер столбца.
     * @return Ссылка на элемент.
     */
    T& operator()(int row, int col);

    /**
     * @brief Доступ к элементу по индексу.
     * @param row Номер строки.
     * @param col Номер столбца.
     * @return Ссылка на элемент.
     */
    const T& operator()(int row, int col) const;
};

template <typename T>
matrix<T>::matrix(int rows, int cols) : rows(rows), cols(cols), matrix_data(rows, std::vector<T>(cols)) {}

template <typename T>
void matrix<T>::fill(const std::function<T()>& generator) {
    for (auto& row : matrix_data) {
        for (auto& elem : row) {
            elem = generator();
        }
    }
}

template <typename T>
void matrix<T>::print() const {
    for (const auto& row : matrix_data) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
const std::vector<T>& matrix<T>::get_row(int index) const {
    return matrix_data[index];
}

template <typename T>
void matrix<T>::insert_row(int index, const std::vector<T>& row) {
    matrix_data.insert(matrix_data.begin() + index, row);
    ++rows;
}

template <typename T>
T& matrix<T>::operator()(int row, int col) {
    return matrix_data[row][col];
}

template <typename T>
const T& matrix<T>::operator()(int row, int col) const {
    return matrix_data[row][col];
}