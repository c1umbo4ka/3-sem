#include <iostream>
#include <locale>
#include <string>
#include "../Domain/Archive.h"
#include "../Domain/Case.h"
#include "../Domain/criminal_case.cpp"

int main() {

    Archive archive;
    int choice;
    setlocale(LC_ALL, "RU");
    while (true) {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Добавить новое дело\n";
        std::cout << "2. Найти дело по осужденному\n";
        std::cout << "3. Найти дела по следователю\n";
        std::cout << "4. Найти дела по статье\n";
        std::cout << "5. Показать все дела\n";
        std::cout << "6. Выйти\n";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 6) break;

        if (choice == 1) {
            std::string convict, detective, article;
            std::cout << "Введите имя осужденного: ";
            std::getline(std::cin, convict);
            std::cout << "Введите имя следователя: ";
            std::getline(std::cin, detective);
            std::cout << "Введите статью: ";
            std::getline(std::cin, article);
            archive.addCase(convict, detective, article);
        }
        else if (choice == 2) {
            std::string convict;
            std::cout << "Введите имя осужденного: ";
            std::getline(std::cin, convict);
            archive.findByConvict(convict);
        }
        else if (choice == 3) {
            std::string detective;
            std::cout << "Введите имя следователя: ";
            std::getline(std::cin, detective);
            archive.findByDetective(detective);
        }
        else if (choice == 4) {
            std::string article;
            std::cout << "Введите статью: ";
            std::getline(std::cin, article);
            archive.findByArticle(article);
        }
        else if (choice == 5) {
            archive.displayAllCases();
        }
        else {
            std::cout << "Неверный выбор, попробуйте еще раз.\n";
        }
    }

    std::cout << "Работа завершена.\n";
    return 0;
}
