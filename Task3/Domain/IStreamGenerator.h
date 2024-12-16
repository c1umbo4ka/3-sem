#pragma once
#include "Generator.h"
#include <iostream>

/**
 * @brief Генератор, считывающий значения из входного потока.
 * @tparam T Тип данных, считываемых из потока.
 */
template <typename T>
class i_stream_generator : public generator<T> {
private:

    /**
     * @brief Ссылка на входной поток.
     */
    std::istream& in;

public:

    /**
     * @brief Конструктор генератора, принимающий входной поток.
     * @param input Входной поток (по умолчанию std::cin).
     */
    explicit i_stream_generator(std::istream& input = std::cin);

    /**
     * @brief Считывает и возвращает значение из потока.
     * @return Считанное значение.
     */
    T generate() override;
};

template <typename T>
i_stream_generator<T>::i_stream_generator(std::istream& input) : in(input) {}

template <typename T>
T i_stream_generator<T>::generate() {
    T value;
    in >> value;
    return value;
}