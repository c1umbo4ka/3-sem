#include <iostream>
#include <string>
#include <locale>
#include "../Domain/Archive.h"


void displayResults(const std::vector<std::string>& results) {
    if (results.empty()) {
        std::cout << "Ничего не найдено.\n";
    }
    else {
        for (const auto& result : results) {
            std::cout << result << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    Archive archive; 
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
        std::cin.ignore();

        if (choice == 6) {
            std::cout << "Выход из программы...\n";
            break;
        }

        if (choice == 1) { 
            std::string convict, detective, article;
            std::cout << "Введите имя осужденного: ";
            std::getline(std::cin, convict);
            std::cout << "Введите имя следователя: ";
            std::getline(std::cin, detective);
            std::cout << "Введите статью: ";
            std::getline(std::cin, article);
            archive.addCase(convict, detective, article);
            std::cout << "Дело добавлено успешно.\n";
        }
        else if (choice == 2) { 
            std::string convict;
            std::cout << "Введите имя осужденного: ";
            std::getline(std::cin, convict);
            auto results = archive.findByConvict(convict);
            std::cout << "Результаты поиска по осужденному \"" << convict << "\":\n";
            displayResults(results);
        }
        else if (choice == 3) { 
            std::string detective;
            std::cout << "Введите имя следователя: ";
            std::getline(std::cin, detective);
            auto results = archive.findByDetective(detective);
            std::cout << "Результаты поиска по следователю \"" << detective << "\":\n";
            displayResults(results);
        }
        else if (choice == 4) { 
            std::string article;
            std::cout << "Введите статью: ";
            std::getline(std::cin, article);
            auto results = archive.findByArticle(article);
            std::cout << "Результаты поиска по статье \"" << article << "\":\n";
            displayResults(results);
        }
        else if (choice == 5) { 
            auto results = archive.displayAllCases();
            std::cout << "Список всех дел:\n";
            displayResults(results);
        }
        else { 
            std::cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    return 0;
}
