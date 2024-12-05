#pragma once
#include "Exercise.h"

class Task_2 : public Exercise {
public:
    void Task1(Matrix& matrix) override {
        // Task2 does not implement Task1
    }

    void Task2(Matrix& matrix) override {
        matrix.insertFirstRowAfterMaxRows();
    }
};


