#pragma once
#include <iostream>
#include <stdexcept>

/**
 * @brief Генератор, считывающий значения из входного потока.
 * @tparam T Тип данных, считываемых из потока.
 */
template <typename T>
class i_stream_generator {
private:

    /**
     * @brief Ссылка на входной поток.
     */
    std::istream& input_stream;

public:

    /**
     * @brief Конструктор генератора, принимающий входной поток.
     * @param input Входной поток (по умолчанию std::cin).
     */
    explicit i_stream_generator(std::istream& input = std::cin) : input_stream(input) {}

    /**
     * @brief Считывает и возвращает значение из потока.
     * @return Считанное значение.
     */
    T generate() {
        T value;
        input_stream >> value;
        return value;
    }
};