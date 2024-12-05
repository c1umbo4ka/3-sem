﻿#pragma once
#include "Generator.h"
#include <random>

class RandomGenerator : public Generator {
private:
    std::uniform_int_distribution<int> distribution;
    std::mt19937 generator;

public:
    RandomGenerator(int min, int max);
    int generate() override;
};

