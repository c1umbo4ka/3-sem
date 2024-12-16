#pragma once

/**
 * @brief Абстрактный класс генератора элементов.
 * @tparam T Тип данных для генерации.
 */
template <typename T>
class generator {
public:

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~generator() = 0;

    /**
     * @brief Генерирует элемент типа T.
     * @return Сгенерированное значение.
     */
    virtual T generate() = 0;
};
