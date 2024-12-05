#pragma once
#include <string>

/**
 * @brief Абстрактный базовый класс для представления общего интерфейса дела.
 */
class Case {
public:

    /**
    * @brief Виртуальный деструктор для корректного удаления объектов через указатели на базовый класс.
    */
    virtual ~Case() = default;

    /**
     * @brief Получить информацию о деле.
     * @return Строка с информацией о деле.
     */
    virtual std::string get_info() const = 0;

    /**
     * @brief Получить имя осужденного.
     * @return Имя осужденного.
     */
    virtual std::string get_convict_name() const = 0;

    /**
     * @brief Получить имя следователя.
     * @return Имя следователя.
     */
    virtual std::string get_detective_name() const = 0;

    /**
     * @brief Получить статью уголовного кодекса.
     * @return Статья уголовного кодекса.
     */
    virtual std::string get_crime_article() const = 0;
};