#pragma once
#include <vector>
#include <iostream>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    size_t rows, columns;

public:
    Matrix(size_t rows, size_t columns);

    void fillWith(int value);
    void fillRandomly(int min, int max);
    void fillFromInput();

    int& operator()(size_t row, size_t col);
    const int& operator()(size_t row, size_t col) const;

    void print() const;

    void replaceMaxInColumnsWithZero();
    void insertFirstRowAfterMaxRows();

    size_t getRows() const { return rows; }
    size_t getColumns() const { return columns; }
};

