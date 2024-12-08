#include <iostream>
#include <memory>
#include <string>
#include <locale>
#include "../Domain/archive.h"
#include "../Domain/criminal_case.h"

void display_menu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Добавить дело\n";
    std::cout << "2. Искать дела по имени осужденного\n";
    std::cout << "3. Искать дела по имени следователя\n";
    std::cout << "4. Искать дела по статье\n";
    std::cout << "5. Показать все дела\n";
    std::cout << "0. Выход\n";
    std::cout << "Введите номер команды: ";
}

void add_case(std::shared_ptr<archive> archive_ptr) {
    std::string convict, detective, article;

    std::cout << "Введите имя осужденного: ";
    std::getline(std::cin, convict);
    std::cout << "Введите имя следователя: ";
    std::getline(std::cin, detective);
    std::cout << "Введите статью: ";
    std::getline(std::cin, article);

    auto new_case = criminal_case::create(convict, detective, article);
    archive_ptr->add_case(new_case);

    std::cout << "Дело добавлено!\n";
}

void search_by_convict(const std::shared_ptr<archive>& archive_ptr) {
    std::string convict;
    std::cout << "Введите имя осужденного для поиска: ";
    std::getline(std::cin, convict);

    auto results = archive_ptr->find_by_convict(convict);
    if (results.empty()) {
        std::cout << "Дела с указанным осужденным не найдены.\n";
    }
    else {
        std::cout << "Найденные дела:\n";
        for (const auto& info : results) {
            std::cout << "- " << info << "\n";
        }
    }
}

void search_by_detective(const std::shared_ptr<archive>& archive_ptr) {
    std::string detective;
    std::cout << "Введите имя следователя для поиска: ";
    std::getline(std::cin, detective);

    auto results = archive_ptr->find_by_detective(detective);
    if (results.empty()) {
        std::cout << "Дела с указанным следователем не найдены.\n";
    }
    else {
        std::cout << "Найденные дела:\n";
        for (const auto& info : results) {
            std::cout << "- " << info << "\n";
        }
    }
}

void search_by_article(const std::shared_ptr<archive>& archive_ptr) {
    std::string article;
    std::cout << "Введите статью для поиска: ";
    std::getline(std::cin, article);

    auto results = archive_ptr->find_by_article(article);
    if (results.empty()) {
        std::cout << "Дела с указанной статьёй не найдены.\n";
    }
    else {
        std::cout << "Найденные дела:\n";
        for (const auto& info : results) {
            std::cout << "- " << info << "\n";
        }
    }
}

void display_all_cases(const std::shared_ptr<archive>& archive_ptr) {
    auto results = archive_ptr->display_all_cases();
    if (results.empty()) {
        std::cout << "В архиве нет дел.\n";
    }
    else {
        std::cout << "Все дела:\n";
        for (const auto& info : results) {
            std::cout << "- " << info << "\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    auto archive_ptr = std::make_shared<archive>();
    int choice;

    do {
        display_menu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Попробуйте снова.\n";
            continue;
        }
        std::cin.ignore(); 

        switch (choice) {
        case 1:
            add_case(archive_ptr);
            break;
        case 2:
            search_by_convict(archive_ptr);
            break;
        case 3:
            search_by_detective(archive_ptr);
            break;
        case 4:
            search_by_article(archive_ptr);
            break;
        case 5:
            display_all_cases(archive_ptr);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            return 0;
        default:
            std::cout << "Неверная команда. Попробуйте ещё раз.\n";
        }
    } while (choice != 0);

    return 0;
}
