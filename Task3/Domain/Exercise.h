#pragma once
#include "Matrix.h"

class Exercise {
public:
    virtual ~Exercise() = default;

    virtual void task_1(Matrix& matrix) = 0;
    virtual void task_2(Matrix& matrix) = 0;
};


