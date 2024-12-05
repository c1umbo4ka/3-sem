#pragma once
#include "Exercise.h"

class Task_1 : public Exercise {
public:
    void Task1(Matrix& matrix) override {
        matrix.replaceMaxInColumnsWithZero();
    }

    void Task2(Matrix& matrix) override {
        // Task1 does not implement Task2
    }
};

