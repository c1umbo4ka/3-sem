#include "../Domain/Matrix.h"
#include "../Domain/RandomGenerator.h"
#include "../Domain/IStreamGenerator.h"
#include "../Domain/Task1.h"
#include "../Domain/Task2.h"
#include <iostream>
#include <locale>

enum class InputMethod {
    Manual = 1,
    Random = 2
};

int main() {
    setlocale(LC_ALL, "RU");
    size_t rows, columns;
    int min, max;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> columns;

    Matrix matrix(rows, columns);

    std::cout << "Введите минимальное значение: ";
    std::cin >> min;
    std::cout << "Введите максимальное значение: ";
    std::cin >> max;

    std::cout << "Выберите способ заполнения матрицы:\n"
        << "1. Вручную\n"
        << "2. Случайными числами\n";
    int choice;
    std::cin >> choice;

    InputMethod inputMethod = static_cast<InputMethod>(choice);

    switch (inputMethod) {
    case InputMethod::Manual: {
        std::cout << "Введите элементы матрицы вручную:\n";
        i_stream_generator inputGen(std::cin);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                std::cout << "Введите элемент [" << i << "][" << j << "]: ";
                matrix(i, j) = inputGen.generate();
            }
        }
        break;
    }
    case InputMethod::Random: {
        std::cout << "Заполняем матрицу случайными числами...\n";
        random_generator randomGen(min, max);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                matrix(i, j) = randomGen.generate();
            }
        }
        break;
    }
    default:
        std::cerr << "Неверный выбор!\n";
        return 1;
    }

    std::cout << "Исходная матрица:\n";
    matrix.print();

    Task1 task1;
    task1.task_1(matrix);
    std::cout << "После выполнения первого задания (замена максимальных элементов столбцов на нули):\n";
    matrix.print();

    Task2 task2;
    task2.task_2(matrix);
    std::cout << "После выполнения второго задания (вставка первой строки после строк с максимальным по модулю элементом):\n";
    matrix.print();

    return 0;
}

