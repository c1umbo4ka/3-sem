#pragma once
#include <memory>
#include "case.h"
#include "archive.h"


/**
 * @brief Класс для представления уголовного дела.
 */
class criminal_case final : public Case, public std::enable_shared_from_this<criminal_case> {
private:

    std::weak_ptr<archive> parent_archive;

    /**
    * @brief Имя осужденного.
    */
    std::string convict_name;

    /**
    * @brief Имя следователя.
    */
    std::string detective_name;

    /**
    * @brief Статья уголовного кодекса.
    */
    std::string crime_article;

    /**
     * @brief Конструктор класса criminal_case.
     * @param convict Имя осужденного.
     * @param detective Имя следователя.
     * @param article Статья уголовного кодекса.
     */
    criminal_case(const std::string& convict, const std::string& detective, const std::string& article);

public:

    /**
     * @brief Статический метод для создания объекта criminal_case.
     * @param convict Имя осужденного.
     * @param detective Имя следователя.
     * @param article Статья уголовного кодекса.
     * @return Умный указатель на объект criminal_case.
     */
    static std::shared_ptr<criminal_case> create(const std::string& convict, const std::string& detective, const std::string& article);
    
    /**
     * @brief Установить указатель на архив.
     */
    void set_archive(std::shared_ptr<archive> parent);


    /**
     * @brief Получить информацию о деле.
     * @return Строка с информацией о деле.
     */
    std::string get_info() const override;

    /**
     * @brief Получить имя осужденного.
     * @return Имя осужденного.
     */
    std::string get_convict_name() const override;

    /**
     * @brief Получить имя следователя.
     * @return Имя следователя.
     */
    std::string get_detective_name() const override;

    /**
     * @brief Получить статью уголовного кодекса.
     * @return Статья уголовного кодекса.
     */
    std::string get_crime_article() const override;
};



