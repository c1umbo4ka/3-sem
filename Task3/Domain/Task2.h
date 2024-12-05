#pragma once
#include "Exercise.h"

class Task_2 : public Exercise {
public:
    void Task1(Matrix& matrix) override {
    }

    void Task2(Matrix& matrix) override {
        matrix.insertFirstRowAfterMaxRows();
    }
};


