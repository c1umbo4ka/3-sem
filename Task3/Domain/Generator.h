#pragma once

/**
 * @brief Абстрактный класс для генерации чисел.
 */
class Generator {
public:

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Generator() = default;

    /**
     * @brief Чисто виртуальный метод для генерации числа.
     * @return Сгенерированное число.
     */
    virtual int generate() = 0;
};

