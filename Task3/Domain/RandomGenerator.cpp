#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int min, int max)
    : distribution(min, max), generator(std::random_device{}()) {}

int RandomGenerator::generate() {
    return distribution(generator);
}
