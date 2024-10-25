#include "../Domain/Vector.h"
#include <iostream>
#include <limits>
#include <locale>

void display_menu() {
    std::cout << "\n=== Меню ===\n";
    std::cout << "1. Добавить элемент (push_back)\n";
    std::cout << "2. Удалить последний элемент (pop_back)\n";
    std::cout << "3. Показать последний элемент (back)\n";
    std::cout << "4. Выйти\n";
    std::cout << "Выберите опцию: ";
}

template <typename T>
void handle_vector_operations(Vector<T>& vec) {
    int choice;
    T value;

    do {
        display_menu();
        std::cin >> choice;

        // Проверка на корректность ввода
        if (std::cin.fail()) {
            std::cin.clear();  // Сбросить флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очистить буфер ввода
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;

            if (std::cin.fail()) {  // Проверка корректности типа для значения
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректный ввод. Попробуйте снова.\n";
            }
            else {
                vec.push_back(value);
                std::cout << "Элемент " << value << " добавлен.\n";
            }
            break;

        case 2:
            vec.pop_back();
            std::cout << "Последний элемент удален.\n";
            break;

        case 3:
            try {
                std::cout << "Последний элемент: " << vec.back() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 4:
            std::cout << "Выход из программы.\n";
            break;

        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }
    } while (choice != 4);
}

int main() {
    setlocale(LC_ALL, "RU");
    int type_choice;

    std::cout << "Выберите тип данных:\n1. int\n2. double\n3. char\nВаш выбор: ";
    std::cin >> type_choice;

    // Проверка корректности ввода для выбора типа данных
    if (std::cin.fail() || type_choice < 1 || type_choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректный выбор типа. Перезапустите программу и выберите правильный тип.\n";
        return 1;
    }

    if (type_choice == 1) {
        Vector<int> vec;
        handle_vector_operations(vec);
    }
    else if (type_choice == 2) {
        Vector<double> vec;
        handle_vector_operations(vec);
    }
    else if (type_choice == 3) {
        Vector<char> vec;
        handle_vector_operations(vec);
    }

    return 0;
}
