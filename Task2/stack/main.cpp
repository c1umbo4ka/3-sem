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

int main() {
    Vector<int> vec;
    int choice;      
    int value; 
    setlocale(LC_ALL, "RU");

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
            if (true) { 
                std::cout << "Последний элемент: " << vec.back() << std::endl;
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

    return 0;
}
