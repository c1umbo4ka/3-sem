#include "../Domain/Vector.h"
#include "../Domain/stack.h"
#include <iostream>
#include <limits>
#include <locale>

void display_menu();

template <typename T>
void handle_vector_operations(Vector<T>& vec, VectorOperations<T>& vec_ops);

int main() {
    setlocale(LC_ALL, "RU");
    int type_choice;

    std::cout << "Выберите тип данных:\n1. int\n2. double\n3. char\nВаш выбор: ";
    std::cin >> type_choice;

    if (std::cin.fail() || type_choice < 1 || type_choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректный выбор типа. Перезапустите программу и выберите правильный тип.\n";
        return 0;
    }

    if (type_choice == 1) {
        Vector<int> vec;
        VectorOperations<int> vec_ops(vec);
        handle_vector_operations(vec, vec_ops);
    }
    else if (type_choice == 2) {
        Vector<double> vec;
        VectorOperations<double> vec_ops(vec);
        handle_vector_operations(vec, vec_ops);
    }
    else if (type_choice == 3) {
        Vector<char> vec;
        VectorOperations<char> vec_ops(vec);
        handle_vector_operations(vec, vec_ops);
    }
    return 0;
}


void display_menu() {
    std::cout << "\n=== Меню ===\n";
    std::cout << "1. Добавить элемент (push_back)\n";
    std::cout << "2. Удалить последний элемент (pop_back)\n";
    std::cout << "3. Показать последний элемент (back)\n";
    std::cout << "4. Показать текущее состояние вектора\n";
    std::cout << "5. Выйти\n";
    std::cout << "Выберите опцию: ";
}

template <typename T>
void handle_vector_operations(Vector<T>& vec, VectorOperations<T>& vec_ops) {
    int choice;
    T value;

    do {
        display_menu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректный ввод. Попробуйте снова.\n";
            }
            else {
                vec_ops.push_back(value);
                std::cout << "Элемент " << value << " добавлен.\n";
            }
            break;

        case 2:
            vec_ops.pop_back();
            std::cout << "Последний элемент удален.\n";
            break;

        case 3:
            try {
                std::cout << "Последний элемент: " << vec_ops.back() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 4:
            vec_ops.display_vector_state();
            break;

        case 5:
            std::cout << "Выход из программы.\n";
            break;

        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }
    } while (choice != 5);
}