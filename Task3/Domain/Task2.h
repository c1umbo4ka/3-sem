#pragma once
#include "Exercise.h"

class Task2 : public Exercise {
public:
    void task_1(Matrix& matrix) override {
    }

    void task_2(Matrix& matrix) override {
        matrix.insert_first_row_after_max_rows();
    }
};


