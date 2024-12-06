#pragma once
#include <vector>
#include <iostream>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    size_t rows, columns;

public:
    Matrix(size_t rows, size_t columns);

    void fill_with(int value);
    void fill_randomly(int min, int max);
    void fill_from_input();

    int& operator()(size_t row, size_t col);
    const int& operator()(size_t row, size_t col) const;

    void print() const;

    void replace_max_in_columns_with_zero();
    void insert_first_row_after_max_rows();

    size_t get_rows() const { return rows; }
    size_t get_columns() const { return columns; }
};

