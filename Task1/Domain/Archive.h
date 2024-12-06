#pragma once
#include <vector>
#include <memory>
#include <string>
#include "case.h"

/**
 * @brief Класс для хранения и управления архивом дел.
 */
class archive : public std::enable_shared_from_this<archive> {

    /**
    * @brief Коллекция дел.
    */
    std::vector<Case*> cases;

public:

    /**
     * @brief Добавляет новое дело в архив.
     * @param Умный указатель на объект класса Case.
     */
    void add_case(std::shared_ptr<Case>& case_ptr);

    /**
     * @brief Находит все дела по имени осужденного.
     * @param convict Имя осужденного.
     * @return Список строк с информацией о найденных делах.
     */
    std::vector<std::string> find_by_convict(const std::string& convict) const;

    /**
     * @brief Находит все дела по имени следователя.
     * @param detective Имя следователя.
     * @return Список строк с информацией о найденных делах.
     */
    std::vector<std::string> find_by_detective(const std::string& detective) const;

    /**
     * @brief Находит все дела по статье уголовного кодекса.
     * @param article Статья уголовного кодекса.
     * @return Список строк с информацией о найденных делах.
     */
    std::vector<std::string> find_by_article(const std::string& article) const;

    /**
    * @brief Выводит все дела в архиве.
    * @return Список строк с информацией о всех делах.
    */
    std::vector<std::string> display_all_cases() const;
};





