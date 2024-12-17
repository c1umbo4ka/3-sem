#include "../Domain/Task1.h"
#include "../Domain/Task2.h"
#include "../Domain/RandomGenerator.h"
#include "../Domain/IStreamGenerator.h"

#include <iostream>
#include <memory>
#include <locale>

enum class DataType {
    INT = 1,
    FLOAT,
    DOUBLE
};

template <typename T>
void run_exercise(int rows, int cols, int fill_choice) {
    
    matrix<T> shared_matrix(rows, cols);

    if (fill_choice == 1) {
        T min_val, max_val;
        std::cout << "Введите минимальное и максимальное значение для случайной генерации: ";
        std::cin >> min_val >> max_val;
        random_generator<T> gen(min_val, max_val);
        shared_matrix.fill([&]() { return gen.generate(); });
    }
    else if (fill_choice == 2) {  
        std::cout << "Введите элементы матрицы по строкам:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                T value;
                std::cout << "Введите элемент [" << i + 1 << "][" << j + 1 << "]: ";
                std::cin >> value;
                if (!std::cin) {  
                    std::cerr << "Ошибка ввода! Пожалуйста, введите числовое значение." << std::endl;
                    return;
                }
                shared_matrix.set_element(i, j, value);
            }
        }
    }
    else {
        std::cerr << "Неверный выбор способа заполнения!" << std::endl;
        return;
    }

    
    std::cout << "\nИсходная матрица:\n";
    shared_matrix.print();

    Task1<T> task1(rows, cols);
    task1.matrix_data = shared_matrix; 
    task1.perform_task();

    std::cout << "\nИзмененная матрица (Task 1):\n";
    task1.matrix_data.print();

    Task2<T> task2(rows, cols);
    task2.matrix_data = shared_matrix; 
    task2.perform_task();

    std::cout << "\nИзмененная матрица (Task 2):\n";
    task2.matrix_data.print();
}

int main() {
    setlocale(LC_ALL, "RU");

    int rows, cols;
    int data_type_choice;
    int fill_choice;
    double min_val, max_val;

    
    std::cout << "Выберите тип данных: \n"
        << "1 - int\n"
        << "2 - float\n"
        << "3 - double\n"
        << "Ваш выбор: ";
    std::cin >> data_type_choice;

    if (data_type_choice != 1 && data_type_choice != 2 && data_type_choice != 3) {
        std::cerr << "Неверный выбор типа данных!" << std::endl;
        return 1;
    }

    
    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cerr << "Количество строк и столбцов должно быть больше нуля!" << std::endl;
        return 1;
    }

    
    std::cout << "Выберите способ заполнения: \n"
        << "1 - случайно\n"
        << "2 - с клавиатуры\n"
        << "Ваш выбор: ";
    std::cin >> fill_choice;

    
    if (fill_choice != 1 && fill_choice != 2) {
        std::cerr << "Неверный выбор способа заполнения!" << std::endl;
        return 1;
    }

    
    switch (data_type_choice) {
    case 1:
        std::cout << "Выбран тип данных: int\n";
        run_exercise<int>(rows, cols, fill_choice);
        break;
    case 2:
        std::cout << "Выбран тип данных: float\n";
        run_exercise<float>(rows, cols, fill_choice);
        break;
    case 3:
        std::cout << "Выбран тип данных: double\n";
        run_exercise<double>(rows, cols, fill_choice);
        break;
    default:
        std::cerr << "Неверный выбор типа данных!" << std::endl;
        return 1;
    }

    return 0;
}