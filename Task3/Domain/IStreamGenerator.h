#pragma once
#pragma once
#include "Generator.h"
#include <iostream>

/**
 * @brief Класс для считывания чисел из потока ввода.
 */
class i_stream_generator : public Generator {
private:

    /**
    * @brief Поток ввода.
    */
    std::istream& input;

public:

    /**
     * @brief Конструктор класса i_stream_generator.
     * @param input Поток ввода.
     */
    i_stream_generator(std::istream& input = std::cin);

    /**
     * @brief Считывает число из потока.
     * @return Считанное число.
     */
    int generate() override;
};


