#include "../Domain/Task1.h"
#include "../Domain/Task2.h"
#include "../Domain/RandomGenerator.h"
#include "../Domain/IStreamGenerator.h"
#include <iostream>
#include <memory>
#include <locale>

template <typename T>
void runexercise(int rows, int cols, int fillChoice, int taskChoice) {
    std::unique_ptr<exercise<T>> exercise;

    if (fillChoice == 1) {
        random_generator<T> gen(0, 100);
        if (taskChoice == 1) {
            exercise = std::make_unique<Task1<T>>(rows, cols);
        }
        else if (taskChoice == 2) {
            exercise = std::make_unique<Task2<T>>(rows, cols);
        }
        else {
            std::cerr << "Неверный выбор задачи!" << std::endl;
            return;
        }
        exercise->fill([&]() { return gen.generate(); });

    }
    else if (fillChoice == 2) {
        i_stream_generator<T> gen;
        if (taskChoice == 1) {
            exercise = std::make_unique<Task1<T>>(rows, cols);
        }
        else if (taskChoice == 2) {
            exercise = std::make_unique<Task2<T>>(rows, cols);
        }
        else {
            std::cerr << "Неверный выбор задачи!" << std::endl;
            return;
        }
        exercise->fill([&]() { return gen.generate(); });

    }
    else {
        std::cerr << "Неверный выбор способа заполнения!" << std::endl;
        return;
    }

    std::cout << "\nИсходная матрица:\n";
    exercise->print();

    exercise->perform_task();

    std::cout << "\nИзмененная матрица:\n";
    exercise->print();
}

int main() {
    setlocale(LC_ALL, "RU");

    int rows, cols, fillChoice, taskChoice, typeChoice;

    std::cout << "Выберите тип данных: \n"
        << "1 - int\n"
        << "2 - float\n"
        << "3 - double\n"
        << "Ваш выбор: ";
    std::cin >> typeChoice;

    if (typeChoice < 1 || typeChoice > 3) {
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
    std::cin >> fillChoice;

    if (fillChoice != 1 && fillChoice != 2) {
        std::cerr << "Неверный выбор способа заполнения!" << std::endl;
        return 1;
    }

    std::cout << "Выберите задачу: \n"
        << "1 - Task1 (замена максимума в столбце на 0)\n"
        << "2 - Task2 (вставка строки после строки с максимальным по модулю элементом)\n"
        << "Ваш выбор: ";
    std::cin >> taskChoice;

    if (taskChoice != 1 && taskChoice != 2) {
        std::cerr << "Неверный выбор задачи!" << std::endl;
        return 1;
    }

    switch (typeChoice) {
    case 1:
        std::cout << "Выбран тип данных: int\n";
        runexercise<int>(rows, cols, fillChoice, taskChoice);
        break;
    case 2:
        std::cout << "Выбран тип данных: float\n";
        runexercise<float>(rows, cols, fillChoice, taskChoice);
        break;
    case 3:
        std::cout << "Выбран тип данных: double\n";
        runexercise<double>(rows, cols, fillChoice, taskChoice);
        break;
    default:
        std::cerr << "Неверный выбор типа данных!" << std::endl;
        return 1;
    }

    return 0;
}
