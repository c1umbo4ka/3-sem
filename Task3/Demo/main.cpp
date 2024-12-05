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

    std::cout << "������� ���������� �����: ";
    std::cin >> rows;
    std::cout << "������� ���������� ��������: ";
    std::cin >> columns;

    Matrix matrix(rows, columns);

    std::cout << "������� ����������� ��������: ";
    std::cin >> min;
    std::cout << "������� ������������ ��������: ";
    std::cin >> max;

    // ����� ������ ����������
    std::cout << "�������� ������ ���������� �������:\n"
        << "1. �������\n"
        << "2. ���������� �������\n";
    int choice;
    std::cin >> choice;

    InputMethod inputMethod = static_cast<InputMethod>(choice);

    switch (inputMethod) {
    case InputMethod::Manual: {
        std::cout << "������� �������� ������� �������:\n";
        IStreamGenerator inputGen(std::cin);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                std::cout << "������� ������� [" << i << "][" << j << "]: ";
                matrix(i, j) = inputGen.generate();
            }
        }
        break;
    }
    case InputMethod::Random: {
        std::cout << "��������� ������� ���������� �������...\n";
        RandomGenerator randomGen(min, max);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                matrix(i, j) = randomGen.generate();
            }
        }
        break;
    }
    default:
        std::cerr << "�������� �����!\n";
        return 1;
    }

    // ������ �������� �������
    std::cout << "�������� �������:\n";
    matrix.print();

    // ���������� ������� �������
    Task_1 task1;
    task1.Task1(matrix);
    std::cout << "����� ���������� ������� ������� (������ ������������ ��������� �������� �� ����):\n";
    matrix.print();

    // ���������� ������� �������
    Task_2 task2;
    task2.Task2(matrix);
    std::cout << "����� ���������� ������� ������� (������� ������ ������ ����� ����� � ������������ �� ������ ���������):\n";
    matrix.print();

    return 0;
}

