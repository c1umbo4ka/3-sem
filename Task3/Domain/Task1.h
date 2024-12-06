#pragma once
#include "Exercise.h"

class Task1 : public Exercise {
public:
    void task_1(Matrix& matrix) override {
        matrix.replace_max_in_columns_with_zero();
    }

    void task_2(Matrix& matrix) override {
    }
};

