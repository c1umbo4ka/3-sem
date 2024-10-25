#include "../Domain/Vector.h"
#include <iostream>
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

        switch (choice) {
        case 1:
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            vec.push_back(value);
            std::cout << "Элемент " << value << " добавлен.\n";
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
    else {
        std::cout << "Некорректный выбор типа.\n";
    }

    return 0;
}
