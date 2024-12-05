#pragma once
#include "Matrix.h"

class Exercise {
public:
    virtual ~Exercise() = default;

    virtual void Task1(Matrix& matrix) = 0;
    virtual void Task2(Matrix& matrix) = 0;
};


