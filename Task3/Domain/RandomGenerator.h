#pragma once
#include "Generator.h"
#include <random>

class random_generator : public Generator {
private:
    std::uniform_int_distribution<int> distribution;
    std::mt19937 generator;

public:
    random_generator(int min, int max);
    int generate() override;
};

