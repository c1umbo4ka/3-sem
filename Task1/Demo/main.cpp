#include <iostream>
#include <string>
#include <limits>
#include <locale>
#include "../Domain/archive.h"
#include "../Domain/criminal_case.h"

enum class menu_option {
    AddCase = 1,
    FindByConvict,
    FindByDetective,
    FindByArticle,
    DisplayAllCases,
    Exit
};

void display_results(const std::vector<std::string>& results);

int main() {
    setlocale(LC_ALL, "RU");
    archive archive_obj;
    int choice;

    while (true) {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Добавить новое дело\n";
        std::cout << "2. Найти дело по осужденному\n";
        std::cout << "3. Найти дела по следователю\n";
        std::cout << "4. Найти дела по статье\n";
        std::cout << "5. Показать все дела\n";
        std::cout << "6. Выйти\n";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Попробуйте снова.\n";
            continue;
        }

        if (choice == static_cast<int>(menu_option::Exit)) {
            std::cout << "Выход из программы...\n";
            break;
        }

        std::cin.ignore();

        switch (static_cast<menu_option>(choice)) {
        case menu_option::AddCase: {
            std::string convict, detective, article;
            std::cout << "Введите имя осужденного: ";
            std::getline(std::cin, convict);
            std::cout << "Введите имя следователя: ";
            std::getline(std::cin, detective);
            std::cout << "Введите статью: ";
            std::getline(std::cin, article);

            archive_obj.add_case(criminal_case::create(convict, detective, article));
            std::cout << "Дело добавлено успешно.\n";
            break;
        }
        case menu_option::FindByConvict: {
            std::string convict;
            std::cout << "Введите имя осужденного: ";
            std::getline(std::cin, convict);
            auto results = archive_obj.find_by_convict(convict);
            std::cout << "Результаты поиска по осужденному \"" << convict << "\":\n";
            display_results(results);
            break;
        }
        case menu_option::FindByDetective: {
            std::string detective;
            std::cout << "Введите имя следователя: ";
            std::getline(std::cin, detective);
            auto results = archive_obj.find_by_detective(detective);
            std::cout << "Результаты поиска по следователю \"" << detective << "\":\n";
            display_results(results);
            break;
        }
        case menu_option::FindByArticle: {
            std::string article;
            std::cout << "Введите статью: ";
            std::getline(std::cin, article);
            auto results = archive_obj.find_by_article(article);
            std::cout << "Результаты поиска по статье \"" << article << "\":\n";
            display_results(results);
            break;
        }
        case menu_option::DisplayAllCases: {
            auto results = archive_obj.display_all_cases();
            std::cout << "Список всех дел:\n";
            display_results(results);
            break;
        }
        default:
            std::cout << "Неверный выбор, попробуйте снова.\n";
            break;
        }
    }

    return 0;
}

void display_results(const std::vector<std::string>& results) {
    if (results.empty()) {
        std::cout << "Ничего не найдено.\n";
    }
    else {
        for (const auto& result : results) {
            std::cout << result << '\n';
        }
    }
}
