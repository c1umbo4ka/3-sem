#include "Matrix.h"
#include <algorithm>
#include <iomanip>
#include <random>

Matrix::Matrix(size_t rows, size_t columns)
    : rows(rows), columns(columns), data(rows, std::vector<int>(columns)) {}


void Matrix::fill_randomly(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    for (auto& row : data) {
        std::generate(row.begin(), row.end(), [&]() { return dis(gen); });
    }
}

void Matrix::fill_from_input() {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            std::cout << "Введите элемент [" << i << "][" << j << "]: ";
            std::cin >> data[i][j];
        }
    }
}

int& Matrix::operator()(size_t row, size_t col) {
    if (row >= rows || col >= columns)
        throw std::out_of_range("Индекс вне диапазона");
    return data[row][col];
}

const int& Matrix::operator()(size_t row, size_t col) const {
    if (row >= rows || col >= columns)
        throw std::out_of_range("Индекс вне диапазона");
    return data[row][col];
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (const auto& elem : row) {
            std::cout << std::setw(4) << elem;
        }
        std::cout << '\n';
    }
}

void Matrix::replace_max_in_columns_with_zero() {
    for (size_t col = 0; col < columns; ++col) {
        int maxElement = data[0][col];
        for (size_t row = 1; row < rows; ++row) {
            if (data[row][col] > maxElement)
                maxElement = data[row][col];
        }
        for (size_t row = 0; row < rows; ++row) {
            if (data[row][col] == maxElement)
                data[row][col] = 0;
        }
    }
}

void Matrix::insert_first_row_after_max_rows() {
    int maxAbsElement = 0;
    for (const auto& row : data) {
        for (const auto& elem : row) {
            maxAbsElement = std::max(maxAbsElement, std::abs(elem));
        }
    }
    std::vector<std::vector<int>> newData;
    for (const auto& row : data) {
        newData.push_back(row);
        if (std::any_of(row.begin(), row.end(), [&](int val) { return std::abs(val) == maxAbsElement; })) {
            newData.push_back(data[0]);
        }
    }
    data = std::move(newData);
    rows = data.size();
}

